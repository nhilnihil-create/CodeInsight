#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=998244353;
using namespace std;


int main(){

int N;
cin>>N;
vector<int>d(N);
rep(i,N)cin>>d[i];

long long ans=1;
if(d[0]!=0)ans=0;

sort(d.begin(),d.end());

map<int,int>mp;
for(int i=1;i<N;i++){
    if(d[i]>1){
        ans*=mp[d[i]-1];
    }
    else if(d[i]==0)ans=0;

    mp[d[i]]++;
    if(ans>mod)ans%=mod;

}

cout<<ans<<endl;
return 0;
}
/*
4
0 1 1 2

2

4
1 1 1 1

0

7
0 3 2 1 2 2 1

24
*/
