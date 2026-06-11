#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
    int N;
    cin>>N;
    int ans=10000;
    int cnt=0;
    int p=0;
    vector<int>W(N);
    rep(i,N){
        cin>>W[i];
        cnt+=W[i];
    }
    rep(i,N){
        cnt-=W[i];
        p+=W[i];
        if(abs(cnt-p)<ans){
            ans=abs(cnt-p);
        }
    }
    cout<<ans<<endl;
}
