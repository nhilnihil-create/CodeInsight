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

int a, b, c, d;
int main() {
    cin >> a >> b >> c >> d;
    for(int i=0; true; i++){
        if(i%2 == 0) c -= b;
        else a -= d;
        if(a<=0 || c<=0) break;
    }
    if(a<=0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
