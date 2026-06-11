#include<bits/stdc++.h>
#define F first
#define S second
#define INF (1<<30)
using namespace std;
typedef pair<int,long long> P;
typedef struct{
  vector<P> to;
  long long min;
}Node;
int n;
int m;
long long daikusutora(int s);
Node node[15];
main(){
  int a,b;
  long long c;
  while(1){
    m=0;
    scanf("%d",&n);
    if(n==0){
      break;
    }
    for(int i=0;i<10;i++){
      node[i].to.clear();
    }
    for(int i=0;i<n;i++){
      scanf("%d %d %d",&a,&b,&c);
      m=max(m,a);
      m=max(m,b);
      node[a].to.push_back(P(b,c));
      node[b].to.push_back(P(a,c));
    }
    m++;
    long long mins=INF;
    int pos=0;
    for(int i=0;i<m;i++){
      long long cnt=0;
      cnt=daikusutora(i);
      //cout<<cnt<<endl;
      if(mins>cnt){
	mins=min(mins,cnt);
	pos=i;
      }
    }
    printf("%d %d\n",pos,mins);
  }
}
long long daikusutora(int s){
  priority_queue<P,vector<P>,greater<P> > que;
  for(int i=0;i<m;i++){
    node[i].min=INF;
  }
  node[s].min=0;
  que.push(P(s,0));
  while(!que.empty()){
    P now=que.top();
    que.pop();
    int basyo=now.F;
    int nowcos=now.S;
    for(int i=0;i<node[basyo].to.size();i++){
      int nbasyo=node[basyo].to[i].F;
      int ncost=node[basyo].to[i].S;
      if(node[nbasyo].min>nowcos+ncost){
	node[nbasyo].min=nowcos+ncost;
	que.push(P(nbasyo,nowcos+ncost));
      }
    }
  }
  long long cnt=0;
  for(int i=0;i<m;i++){
    cnt+=node[i].min;
  }
  return cnt;
}