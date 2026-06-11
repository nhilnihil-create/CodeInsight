#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
int n;
cin >> n;
vector<int> a(n);
rep(i,n) cin >> a.at(i);

sort(a.begin(),a.end());
int ans = a.at(n/2) - a.at(n/2-1);
cout << ans << endl;
}
