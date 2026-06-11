
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <complex>
#define FIXED_FLOAT(x)  std::fixed <<std::setprecision(7)<<(x)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace  std;

using ll = long long;
const ll mod = 1e9 + 7;
typedef pair<ll ,ll > pairs;
typedef complex<ll> G;
const int N=2e5+5;

const ll INF = 1e18;

void done() {
    int n, k;
    cin >> n>> k;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i=2; i<= n;i++) {
        a[i] += a[i-1];
    }
    int best = 0;
    a[0] = 0;
    for(int i =k;i <=n;i++) {
        best = max(best, a[i]-a[i-k]);
    }
    cout << FIXED_FLOAT((best+k)*.5);
}
void solve() {

    int n;
    cin >>n;
    vector<int>a(n);
    vector<int>b(n);
    vector<long double>c;
    for(int i=0;i < n;i++) {
        cin >> a[i];
    }
    int r = 0;
    for(int i=0;i < n;i++) {
        cin >> b[i];
        if(a[i]!=0) {
            c.push_back(b[i]/a[i]*1.0);
        }else if(b[i]=='0') {
            r++;
            c.push_back(-999999999);
        }
        else {
            c.push_back(-999999999);
        }
    }
    int sum = 1;
    int best = 0;
    sort(c.begin(), c.end());
    for(int i=1;i < n;i++) {
        if(c[i]==c[i-1] && c[i-1]!=-999999999) {
                sum++;
        }
        else {
            if(sum > best && c[i-1]!=-999999999) {
                best = sum;
                sum = 1;
            }
        }
    }
    if(sum > best && c[n-1]!=-999999999) {
        best = sum;
    }
    cout << best+r << '\n';
}
void another() {
    int n;cin >> n;
    vector<int>a(n);
    for(int i=0;i < n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int p = a[n-1];
    int ans = 0;


}
void test_case() {
    int t;
    cin >> t;
    while(t--)done();
}
int main() {

    fast;
    done();

}

