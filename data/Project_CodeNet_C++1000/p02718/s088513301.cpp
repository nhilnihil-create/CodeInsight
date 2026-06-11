#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i); 
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long sum=0;
    rep(i,n) sum +=a.at(i);
    if(a.at(m-1) * 4 * m >= sum){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
