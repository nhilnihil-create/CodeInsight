#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl 
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    int now = 0;
    rep(i,n-1){
        if(a[i] >= a[i+1]) now++;
        else now = 0;
        ans = max(ans,now);
    }
    cans;
    return 0;
}   