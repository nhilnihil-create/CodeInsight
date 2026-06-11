#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N; cin >> N;
    vector<ll> A(N + 1);
    vector<ll> sum(N + 2, 0);
    rep(i, N + 1){
        cin >> A[i];
        sum[i + 1] += sum[i] + A[i];
    }
    ll ans = 1;
    ll f_node = 1;
    if(N == 0 && A[0] == 1){
        cout << 1 << endl;
        return 0;
    }else if(A[0] != 0){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i < N + 1; i++){
        // cout << f_node << " " << sum[N + 1] - sum[i] << endl;
        ll node = min(f_node*2, sum[N + 1] - sum[i]);
        if(node - A[i] < 0){
            cout << -1 << endl;
            return 0;
        }
        f_node = node - A[i];
        ans += node;
    }
    cout << ans << endl;
}
