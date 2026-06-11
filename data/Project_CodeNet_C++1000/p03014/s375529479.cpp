#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;

char maze[2010][2010];
ll ansmaze[2010][2010];


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int h,w;cin>>h>>w;

	rep(i,h){
		rep(j,w){
			cin>>maze[i][j];
		}
	}


	int cnt=0;
	int s=0;
	rep(i,h){
		rep(j,w){
			if(maze[i][j] =='.'){
				if(cnt ==0){
					s=j;
				}
				cnt++;
			}else  {
				for(int k=s; k<j; k++){
					ansmaze[i][k] = cnt;
				}
				s=j;
				cnt =0;
			}
			if(j== w-1 && cnt !=0){
				for(int k=s; k<=j; k++){
					ansmaze[i][k] = cnt;
				}
				cnt=0;
			}
		}
	}
/*
	rep(i,h){
		rep(j,w){
			cout<<ansmaze[i][j];
		}
		cout<<endl;
	}
	cout<<endl;

*/

	cnt=0;
	 s=0;
	rep(i,w){
		rep(j,h){
			if(maze[j][i] =='.'){
				if(cnt ==0){
					s=j;
				}
				cnt++;
			}else  {
				for(int k=s; k<j; k++){
					ansmaze[k][i] += cnt;
				}
				s=j;
				cnt =0;
			}
			if(j== h-1 && cnt !=0){
				for(int k=s; k<=j; k++){
					ansmaze[k][i] += cnt;
				}
				cnt=0;
			}
		}
	}
/*
	rep(i,h){
		rep(j,w){
			cout<<ansmaze[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	ll ans =0;
	rep(i,h){
		rep(j,w){
			ans = max(ans,ansmaze[i][j]-1);
		}
	}
	writeln(ans);








}
