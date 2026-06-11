#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;

int main(){
 int N;
 cin>>N;
 long long x[N];
 long long y[N];
 rep(i,N){
     cin>>x[i]>>y[i];
 }
map<pair<long long,long long> ,int>mp;
 for(int i=0;i<N;i++){
     for(int k=0;k<N;k++){
         if(i==k)continue;
        long long dx=x[i]-x[k];
        long long dy=y[i]-y[k];
        mp[make_pair(dx,dy)]++;
     }
 }
auto iter=mp.begin();
long long ans=0;
while(iter!=mp.end()){
    long long p=iter->second;
    ans=max(ans,p);
    iter++;
}
cout<<N-ans<<endl;
 return 0;
}
/*

by myself

first 33m17s
second 6m39s

2
1 1
2 2

1

3
1 4
4 6
7 8

1


4
1 1
1 2
2 1
2 2

2
*/