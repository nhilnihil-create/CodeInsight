#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(x, y) for (int x=0; x<y; x++) 

void print(vector<vector<int> > board)
{
#if 0
	cerr << "------" << endl;
	rep(y, board.size()) {
		rep(x, board[y].size()) {
			if (board[y][x] != -1) 
				cerr << board[y][x] << " ";
			else cerr << "  ";
		}
		cerr << endl;
	}
	cerr << "------" << endl;
#endif
}

int main()
{
	int H;
	while (cin>>H, H) {
		vector<vector<int> > board(H, vector<int>(6));
		rep(i, H) rep(j, 5) cin >> board[i][j];
		rep(i, H) board[i][5] = -1;
		
		print(board);
		
		int ans=0;
		
		while (true) {
			// erase
			bool update = false;
			print(board);
			//cerr << "A" << endl;
			
			rep(y, H) {
				int cnt=1;
				for (int x=1; x<6; x++) {
					if (board[y][x] == board[y][x-1] && board[y][x] != -1) {
						cnt++;
					} else {
						if (cnt>=3) {
							for (int i=x-1; i>=x-cnt; i--) {
								ans += board[y][i];
								board[y][i] = -1;
							}
							update = true;
							cnt = 0;
						} else {
							cnt = 1;
						}
					}
				}
			}	
			
			//cerr << "B" << endl;
			
			// drop
			for (int y=H-2; y>=0; y--) {
				for (int x=0; x<5; x++) {
					int yy=y;
					while (yy<H-1 && board[yy+1][x] == -1) {
						swap(board[yy+1][x], board[yy][x]);
						yy++;
					}
				}
			}
			
			//cerr << "C" << endl;
		
			if (!update) break;
		}
		cout << ans << endl;
	}
}