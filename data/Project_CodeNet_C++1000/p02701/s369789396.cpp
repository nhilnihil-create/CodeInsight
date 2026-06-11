#include <iostream>
#include <set>
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
    set<string> s;
    rep(_, 0, n){
        string a; cin >> a;
        s.insert(a);
    }
    cout << s.size() << endl;
    return 0;
}
