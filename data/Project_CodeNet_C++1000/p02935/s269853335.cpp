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
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(),v.end());
    double now = v[0];
    for(int i=1; i<n; i++){ 
        now += v[i];
        now /= 2.0;
    }
    cout << now << endl;
    return 0;
}