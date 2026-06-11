#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
typedef pair<int,int> P;
struct edge{int to, id;};
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod 1000000007

using graph = vector<vector<ll>>;

int main(){
    ll a,b,k;
    cin >> a >> b >> k;
    if(k <= a){
        cout << a-k << " " <<b << endl;
    }
    else if(k > a && k <= a+b){
        cout << 0 << " " << b - k + a << endl;
     }
     else{
         cout << 0 << " " << 0 << endl;
     }
}