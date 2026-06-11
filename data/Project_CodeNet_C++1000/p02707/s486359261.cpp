#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 2; i <= (int)(n); i++)
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> head(N+1,0);
    rep(i,N){
        ll num;
        cin>>num;
        head[num]++;
    }
    for(int i=1;i<=N;i++){
        cout<<head[i]<<endl;
    }
    return 0;
}