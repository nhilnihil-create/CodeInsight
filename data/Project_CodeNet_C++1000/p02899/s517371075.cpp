#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> num(n);
    rep(i, n) num[i] = i;
    sort(all(num),[&](int x, int y){
        return a[x] < a[y];
    });
    rep(i, n) cout << num[i]+1 << " ";
    cout << endl;
}