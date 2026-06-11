#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M,res;
    cin >> N >> M;
    vector<ll> h(N+1);
    vector<ll> highest(N+1,0);
    for (int i = 1; i <= N; i++)cin>>h[i];
    for (int i = 0; i < M; i++) {
        ll a,b;
        cin >> a >> b;
        highest[a]=max(highest[a],h[b]);
        highest[b]=max(highest[b],h[a]);
    }
    res=0;
    for(int i=1;i<=N;i++){
        if(highest[i]<h[i])res++;
    }
    cout<<res;
    return 0;
}