#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;

int main(){
  int a,b;
  while(cin>>a>>b,a+b){
    int MAP[a+1][b+1]={};
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      int x,y;
      cin>>x>>y;
      MAP[x][y]=1;
    }
    queue<pair<int,int> >que;
    que.push(mp(1,1));
    int ans=0;
    while(!que.empty()){
      pair<int,int>now=que.front();
      que.pop();
      if(now.F==b&&now.S==a){
	ans++;
	continue;
      }
      if(now.F+1>0&&now.F+1<=b&&!MAP[now.S][now.F+1]){
	que.push(mp(now.F+1,now.S));
      }
      if(now.S+1>0&&now.S+1<=a&&!MAP[now.S+1][now.F]){
	que.push(mp(now.F,now.S+1));
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}