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
    vector<ll> a(n);
    vector<ll> sheet(n+1);
    rep(i,n) {
        cin >> a[i];
        sheet[a[i]]++;
    }
    ll tot = 0;
    for(int i=1; i<=n; i++){
        if(sheet[i]!=0) tot += sheet[i]*(sheet[i]-1)/2;
    }
    for(int i=0; i<n; i++){
        int now = sheet[a[i]];
        if(now!=0){
            cout << tot-(now-1)*now/2+(now-1)*(now-2)/2 << endl;
        }
        else{
            cout << tot << endl;
        }
    }
    return 0;
}