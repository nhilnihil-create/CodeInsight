#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>> graph;

int main(void){
   int N;
   cin>>N;
   vector<long long> X(N),L(N);
   for(int i=0;i<N;i++){
      cin>>X[i]>>L[i];
   }
   vector<pair<long long,long long>> range(N);
   for(int i=0;i<N;i++){
      range[i]=make_pair(X[i]+L[i],X[i]-L[i]);
   }
   sort(range.begin(),range.end());
   int ans=0;
   long long now=-1000000007;
   for(int i=0;i<N;i++){
      if(range[i].second>=now){
         ans++;
         now=range[i].first;
      }
   }
   cout<<ans<<endl;
   return 0;
}