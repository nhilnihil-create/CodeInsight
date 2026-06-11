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

int x;
int main() {
    cin >> x;

    rep(i, -119, 120){
        rep(j, -119, 120){
            ll a = i*i*i*i*i;
            ll b = j*j*j*j*j;
            if(x == a-b){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}
