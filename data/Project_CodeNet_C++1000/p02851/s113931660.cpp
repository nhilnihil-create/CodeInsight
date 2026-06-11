#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
using ll = long long int;

int n;
ll k;
vector<ll> A;
vector<ll> S;

int main(){
    cin >> n >> k;
    A.resize(n+3);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        A[i] %= k;
    }

    S.resize(n+3);
    S[0] = 0;
    ll tot = 0;
    ll ans = 0;
    map<ll, ll> M;
    M[0] = 1;
    for(int i = 1; i <= n; i++){
        if (i >= k){
            M[S[i-k]]--;
        }
        tot += A[i];
        int ik = i % k;
        ll now = (tot + k - ik) % k;
        if (M.find(now) != M.end()){
            ans += M[now];
            M[now]++;
        }
        else M[now] = 1;

        S[i] = now;
    }
    cout << ans << endl;
    return 0;
}