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
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    h[0]--;
    rep(i,n-1){
        if(h[i+1]<h[i]) {
            cno;
            return 0;
        }
        if(h[i+1] > h[i]) h[i+1]--;
    }
    cyes;
    return 0;
}