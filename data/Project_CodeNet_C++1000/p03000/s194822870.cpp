#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
    int N,X;
    cin>>N>>X;
    vector<int>L(N);
    int ans=0;
    int cnt=0;
  bool a=false;
    rep(i,N){
        cnt++;
        cin>>L[i];
        ans+=L[i];
        if(X<ans){
          cout<<cnt<<endl;
          a=true;
            break;
        }
    }
if(a==false){
  cout<<N+1<<endl;
}
}
