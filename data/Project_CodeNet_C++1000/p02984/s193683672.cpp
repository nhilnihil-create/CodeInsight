#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    ll all_sum = 0;
    ll sub_sum = 0;
    rep(i,N){
        all_sum += vec[i];
    }
    for (int i = 1; i <= N - 2; i += 2){
        sub_sum += (2 * vec[i]);
    }
    vector<ll> ans(0);
    ans.push_back(all_sum - sub_sum);
    rep(i,N - 1){
        ans.push_back(2 * vec[i] - ans[i]);
    }
    rep(i,N){
        cout << ans[i] << " ";
    }
    cout << endl;
}
