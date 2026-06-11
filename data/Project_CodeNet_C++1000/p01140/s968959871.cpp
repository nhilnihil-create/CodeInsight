#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
  int N,M,i,j,t,ans;
  while(cin>>N>>M,N|M){
    vector<int>h(N),w(M);
    map<int,int>m;
    for(i=0;i<N;i++)cin>>h[i];
    for(i=0;i<M;i++)cin>>w[i];

    for(i=0;i<N;i++){
      t=0;
      for(j=i;j<N;j++){
	t+=h[j];
	m[t]++;
      }
    }
    ans=0;
    for(i=0;i<M;i++){
      t=0;
      for(j=i;j<M;j++){
	t+=w[j];
	if(m.count(t))ans+=m[t];
      }
    }

    cout<<ans<<endl;
  }
}