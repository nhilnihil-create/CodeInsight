#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl;
#define cyes cout << "Yes" << endl; 
#define cno cout << "No" << endl; 
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    a[0] = 1e9;
    int ans = 0;
    for(int i=1; i<n; i++){
        cin >> a[i];
        ans += min(a[i-1],a[i]);
    }
    ans += a[n-1];
    cans;
    return 0;
}