#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

int main(){

    string s, t;
    cin >> s >> t;

    int a,b;
    cin >> a >> b;

    string u;
    cin >> u;

    if(s == u){
        cout << a - 1 << " " << b << endl;
    }else{
        cout << a << " " << b - 1 << endl;
    }

    return 0;
}
