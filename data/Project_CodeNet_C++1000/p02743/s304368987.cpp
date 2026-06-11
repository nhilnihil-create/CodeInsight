#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;
const int MOD = 1000000007;

int main(){
    ll a,b,c; cin >>a>>b>>c;
    if((c-a-b)*(c-a-b)>4*a*b && c-a-b>0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}