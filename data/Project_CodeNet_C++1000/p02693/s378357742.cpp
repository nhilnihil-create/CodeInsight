#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl

int k, a, b;
int main() {
    cin >> k >> a >> b;
    rep(i, a, b+1){
        if(i%k == 0){
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;
    return 0;
}
