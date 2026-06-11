#include<string>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(i = 0; i < n; i++)]
#define DEBUG
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main(){
	int N, M;
	while(cin>>N, N){
		bool gem[21][21];
		int cx, cy;
		cx = cy = 10;
		rep(i, 21)rep(j, 21)gem[i][j] = 0;
		rep(i, N){
			int x,y;
			cin>>x>>y;
			gem[x][y] = true;
		}
		cin>>M;
		rep(i, M){
			string s;
			int l, d;
			cin>>s>>l;
			if(s == "E")d = 0;
			else if(s == "W")d = 1;
			else if(s == "N")d = 2;
			else d = 3;
			while(l--){
				cx += dx[d]; cy += dy[d];
				gem[cx][cy] = false;
			}
		}
		bool flag = false;
		rep(i, 21)rep(j, 21){
			flag = flag || gem[i][j];
		}
		cout<<(flag?"No":"Yes")<<endl;
	}
	return 0;
}