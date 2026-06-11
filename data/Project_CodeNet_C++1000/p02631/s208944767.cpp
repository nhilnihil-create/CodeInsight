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

int n;
int main() {
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    int wx = a[0];
    rep(i, 1, n) wx ^= a[i];

    rep(i, 0, n){
        int out = wx ^ a[i];
        cout << out;
        if(i != n-1) cout << " ";
    }
    cout << endl;
    return 0;
}
