#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,K;
    cin >> N >> K;
    vector<double> vec(N);
    rep(i,N){
        cin >> vec[i];
        vec[i] = (vec[i] + 1) * 0.5;
    }
    double ans = 0;
    double sub_ans = 0;
    rep(i,K){
        sub_ans += vec[i];
    }
    ans = sub_ans;
    rep(i,N - K){
        sub_ans += vec[K + i];
        sub_ans -= vec[i];
        ans = max(ans,sub_ans);
    }
    cout << fixed << setprecision(15) << ans << endl;
}

