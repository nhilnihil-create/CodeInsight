#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<iomanip>
#include<tuple>
#include<bitset>


using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define printfloat(x) cout << fixed << setprecision(7) << (x) << endl;
#define printbit(x) cout << bitset<15>(x) << endl;
using ll = long long int;



long double pi = 3.14159265359;



priority_queue<int> q;
int n,m;
int t;

int main(){
    cin >> n >> m;
    rep(i,n) {
        cin >> t;
        q.push(t);
    }
    rep(i,m){
        int x = q.top();q.pop();
        x = x/2;
        // cout << x << endl;
        q.push(x);
    }
    ll ans=0;
    rep(i,n){
        ans += q.top();q.pop();
    }
    cout << ans << endl;

return 0;
}