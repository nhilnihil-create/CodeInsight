#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;
#define rep1(i,n) for (int i=1; i<=n; i++)
#define rep0(i,n) for (int i=0; i<n; i++)
#define zarray(x,n) x[n+1]; rep1(i,n) {x[i]=0;} 

int main() {
    int n;
    cin >> n;
    map<string,int> a;
    rep0(i,n) {
        string s;
        cin >> s;
        a[s]++;
    }
    int ans = a.size();
    cout << ans << endl;
}
