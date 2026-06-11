#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N; cin>>N;
    int A[N];
    rep(i, N) cin>>A[i];

    map<int, int> v;
    rep(i, N){
        int a=i+1;
        if(a-A[i] > 0){
            v[a-A[i]]++;
        }
    }

    ll ans=0;
    rep(i, N){
        int b=i+1;
        ans+=v[b+A[i]];
    }

    cout << ans << endl;
    return 0;
}