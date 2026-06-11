#include <bits/stdc++.h>
using namespace std;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;
 
int main() {
    int n, k;
    cin >> n >> k;
    int s = 0;
    vector<int> A;
    rp(i, 0, n) {
        int a; cin >> a;
        A.emplace_back(a);
        s+=a;
    }
    vector<int> div;
    for(int i = 2; i*i <= s; i++) {
        if(s%i==0) {
            div.emplace_back(i);
            div.emplace_back(s/i);
        }
    }
    div.emplace_back(s);
    int res = 1;
    for(auto d: div) {
        // printf("d = %d\n", d);
        vector<int> rem;
        for(auto a: A) rem.emplace_back(a%d);
        sort(rem.begin(), rem.end());
        vector<int> sum_p(n+1);
        vector<int> sum_m(n+1);
        rp(i, 0, n) sum_p[i+1] = sum_p[i] + rem[i];
        for(int i = n-1; i>=0; i--) sum_m[i] = sum_m[i+1] + d - rem[i];
        rp(i, 0, n+1) {
            if(sum_p[i] == sum_m[i]) {
                int sum = 0;
                rp(j, 0, i) sum+=rem[j];
                if(sum<=k) chmax(res, d); 
            }
        }   
    }
    cout << res << endl;
    return 0;
}