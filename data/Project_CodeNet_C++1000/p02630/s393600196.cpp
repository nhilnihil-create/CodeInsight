#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
int n;
const ll t = 200000;
cin >> n;
ll sum = 0;
vector<ll> a(t);
for(int i = 0; i<n;i++){
    ll l;
    cin >> l;
    a[l]++;
    sum += l;

}

cout << endl;
int q;
cin >> q;
for(int i=0; i < q; i++){
    ll b,c;
    cin >> b >> c;
    sum -= b*a[b];
    sum += c*a[b];
    a[c] += a[b];
    a[b] = 0;
    cout << sum << endl;

}
return 0;
}