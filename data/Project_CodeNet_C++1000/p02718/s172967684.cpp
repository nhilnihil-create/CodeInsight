#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()

int main(void)
{
    int n, m, sum=0;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a),greater<int>());
    if(a[m-1]*4*m >= sum) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}