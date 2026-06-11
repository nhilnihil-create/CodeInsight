#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    int sum = 0;
    rep(i, n)sum += a[i];
    vector<int> p;
    for(int i = 1; i * i <= sum; i++){
        if(sum % i == 0){
            p.push_back(i);
            p.push_back(sum / i);
        }
    }
    int ans = 0;
    for(int x : p){
        vector<int> y(n);
        rep(i, n)y[i] = a[i] % x;
        sort(y.begin(), y.end());
        int cnt = 0;
        int l = 0;
        int r = n - 1;
        while(l < r){
            if(y[l] + y[r] < x){
                y[r] += y[l];
                cnt += y[l];
                l++;
            }else if(y[l] + y[r] == x){
                cnt += y[l];
                l++;
                r--;
            }else{
                cnt += x - y[r];
                y[l] -= x - y[r];
                r--;
            }
            if(cnt > k)break;
        }
        if(cnt <= k)ans = max(ans, x);
    }
    cout << ans << endl;
}