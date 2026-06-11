
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
ll H;
ll DFS(ll i){
    ll ans=0;
    if(i==1){
        ans=1;
    }
    else{
        ans=DFS(i/2)*2+1;
    }
    return ans;
}
int main(){
  cin>>H;
  cout<<DFS(H)<<endl;
}
