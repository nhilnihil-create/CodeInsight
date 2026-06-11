
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
typedef pair<int , int > pairs;
typedef complex<ll> G;
const int N=2e5+5;

const ll INF = 1e18;

void done() {
    string a, b;
    cin >> a >> b;
    int n, k;
    cin >> n >> k;
    string p;
    cin >> p;
    if(p==a) {
        cout << n-1 << " "  << k;
    }
    else cout << n << " " << k-1 << '\n';

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

    string s;
    cin >> s;
    int left= 0, right = 0;
    int d = (s[0]=='<') ?1 : 0;
    int c = (s[n-1]=='>')?1 : 0;

    for(int i=0;i < n;i++) {
        if(i!=0 && s[i]=='<')left++;
        else if(i!=n-1 && s[i]=='>')right++;
    }
    if(left <= right) {
        swap(left, right);
        swap(d, c);
    }
    if(d) {
        cout << max(1, right-1) << '\n';
    }
    else cout << max(0, right-1) << '\n';



}
void test_case() {
    int t;
    cin >> t;
    while(t--)solve();
}
int main() {

    fast;
    done();

}

