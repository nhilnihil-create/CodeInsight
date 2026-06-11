#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    ll n,k;
    cin>>n>>k;
    ll now=1001001001001001001;

    rep(i,1001){
        if(n>=k){
            n%=k;
            now=min(now,n);
            if(now==0){
                cout<<0<<endl;
                return 0;
            }
        }
        else{
            n=k-n;
            now=min(now,n);
        }
    }
    cout<<now<<endl;
    return 0;
}