#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#include<iomanip>
#include<math.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;
#define INF 1000000000000000LL

int main(){
    ll N; cin >> N;
    ll a[N+1];
    ll node = 0;
    rep(i, N+1){
        cin >> a[i];
    }
    ll c[N+2];
    c[0] = 1;
    
    for(int i=0; i<N+1; i++){
        c[i+1] = min(2LL*(c[i]-a[i]), INF);
        // cout << a[i] << endl;
        // cout << "c[" << i << "] = " << c[i] << endl;
        if(c[i+1] < 0){
            cout << -1 << endl;
            return 0;
        }
    }

    node += a[N];
    ll now = a[N];
    
    // cout << "now "<< now << endl;
    for(int i=N-1; i>-1; i--){
        now += a[i];
        if(now < c[i]){
            node += now;
        }else{
            node += c[i];
        }
        // cout << "now "<< now << endl;
    }
    cout << node << endl;
}
