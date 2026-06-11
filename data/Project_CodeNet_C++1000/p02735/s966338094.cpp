#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()
#define mod 1000000007
int x[2]={0,1};
int y[2]={1,0};
int main(){
	deque<pair<int,int>> q;
	int h,w;
	cin>>h>>w;
	q.push_back(make_pair(0,0));
	char s[h][w];
	int cost[h][w];
	rep(i,h)rep(j,w)cin>>s[i][j];
	rep(i,h)rep(j,w)cost[i][j]=1000000000;
	if(s[0][0]=='.')cost[0][0]=0;
	else cost[0][0]=1;
	pair<int,int> now;
	int newx,newy;
	while(1){
		now=q.front();
		q.pop_front();
		rep(i,2){
			newy=now.first+y[i];
			newx=now.second+x[i];
			if(0<=newy&&newy<h&&0<=newx&&newx<w){
				if(s[now.first][now.second]=='#'||s[newy][newx]=='.'){
						if(cost[newy][newx]>cost[now.first][now.second]){
							cost[newy][newx]=cost[now.first][now.second];
							q.push_front(make_pair(newy,newx));
						}
					}
					else{
						if(cost[newy][newx]>cost[now.first][now.second]+1){
							cost[newy][newx]=cost[now.first][now.second]+1;
							q.push_back(make_pair(newy,newx));
						}
					}
				}
			if(newy==h-1&&newx==w-1){
				cout<<cost[newy][newx];
				return 0;
			}
		}
	}		
	return 0;
}