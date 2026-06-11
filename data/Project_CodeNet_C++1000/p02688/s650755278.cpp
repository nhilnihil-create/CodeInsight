#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    int N,K; cin >> N >> K;
    vector<int> v(N+1);
    rep(i,K){
        int d; cin >> d;
        rep(j,d){
            int a; cin >> a;
            v[a]++;
        }
    }

    ll res = 0;
    for(int i=1;i<=N;i++){
        if(v[i]==0) res++;
    }
    cout << res << endl;
}