#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    int sum = 0;
    rep(i, k) sum += a[i];
    
    cout << sum << endl;
    return 0;
}