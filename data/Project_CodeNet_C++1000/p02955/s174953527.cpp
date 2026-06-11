#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    ll sum = 0;
    rep(i,N){
        sum += A[i];
    }
    vector<ll> divisors(0);
    for (ll i = 1; i * i <= sum; i++){
        if (sum % i == 0){
            divisors.push_back(i);
            divisors.push_back(sum / i);
        }
    }
    sort(all(divisors));
    ll len = divisors.size();
    ll ans = 1;
    rep(i,len){
        ll ans_sub = 0;
        vector<ll> count(0);
        rep(j,N){
            ll count_sub = divisors[i] - A[j] % divisors[i];
            count.push_back(count_sub);
        }
        sort(all(count));
        vector<ll> count_sum(N);
        vector<ll> count_sum_reverse(N);
        count_sum[0] = count[0];
        rep(j,N - 1){
            count_sum[j + 1] = count_sum[j] + count[j + 1];
        }
        count_sum_reverse[N - 1] = divisors[i] - count[N - 1];
        rep(j,N - 1){
            count_sum_reverse[N - 2 - j] = count_sum_reverse[N - 1 - j] + (divisors[i] - count[N - 2 - j]);
        }
        /*rep(j,N){
            cout << count_sum[j] << " ";
        }
        cout << endl;
        rep(j,N){
            cout << count_sum_reverse[j] << " ";
        }
        cout << endl;*/
        rep(j,N - 1){
            if (count_sum[j] == count_sum_reverse[j + 1]) ans_sub = count_sum[j];
        }
        if (ans_sub <= K) ans = max(ans, divisors[i]);
    }
    cout << ans << endl;
}