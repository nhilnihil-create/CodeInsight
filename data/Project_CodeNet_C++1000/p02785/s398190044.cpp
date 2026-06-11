#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N,K;cin>>N>>K;
    vector<int> H(N);
    for (int i = 0; i < N; i++){
        cin>>H[i];
    }
    sort(H.begin(),H.end());
    ll ans=0;
    for (int i = 0; i < N-K; i++){
        ans+=H[i];
    }
    cout<<ans<<endl;
}