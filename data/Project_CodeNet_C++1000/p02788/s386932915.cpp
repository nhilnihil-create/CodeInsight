#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;

int main() {
    ll n, d, a;
    cin >> n >> d >> a;
    vector<P> x(n);
    rep(i, n)cin >> x[i].first >> x[i].second;
    sort(x.begin(), x.end());
    rep(i, n)x[i].second = (x[i].second+a-1) / a;
    priority_queue<P, vector<P>, greater<P>> que;
    int sum = x[0].second;
    que.push(make_pair(x[0].first+2*d, -sum));
    ll ans = sum;
    for(int i = 1; i < n; i++){
        if(!que.empty()){
            while(que.top().first < x[i].first){
                P p = que.top();
                que.pop();
                sum += p.second;
                if(que.empty())break;
            }
        }
        x[i].second -= sum;
        if(x[i].second > 0){
            ans += x[i].second;
            que.push(make_pair(x[i].first+2*d, -x[i].second));
            sum += x[i].second;
        }
    }
    cout << ans << endl;
}