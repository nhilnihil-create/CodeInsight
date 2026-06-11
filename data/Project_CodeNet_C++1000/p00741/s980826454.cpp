#include <iostream>
#include <deque>
using namespace std;

#define REP(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

class Point{
public:
	int x,y;

	Point(int tx,int ty){
		x = tx;
		y = ty;
	}
};

int w,h;
int t[52][52];
int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,1,1,1};

int solve(void){
	int res = 0;

	rep(i,h) rep(j,w) if(t[i][j] == 1) {
		res++;
		deque<Point> stack;
		stack.push_back(Point(j,i));

		while(!stack.empty()){
			Point p = stack.back(); stack.pop_back();
			t[p.y][p.x] = 0;

			rep(k,8){
				int nx = p.x + dx[k];
				int ny = p.y + dy[k];

				if(nx>=0 && nx<w && ny>=0 && ny<h && t[ny][nx]==1){
					stack.push_back(Point(nx,ny));
				}
			}
		}
	}

	return res;
}

int main(void){
	while(cin>>w>>h && (w||h)){
		rep(i,h) rep(j,w) cin>>t[i][j];
		cout<<solve()<<endl;
	}


	return 0;
}