#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
    a--; b--; c--; d--;
    string s; cin >> s;
    if(c < b || (c > b && c < d)){
        bool ok = true;
        repr(i,a,c){
            if(s[i] == '#' && s[i+1] == '#') ok = false;
        }
        repr(i,b,d){
            if(s[i] == '#' && s[i+1] == '#') ok = false;
        }
        cout << (ok?"Yes":"No") << endl;
    }
    else{
        bool ok = false;
        repr(i,a,c){
            if(s[i] == '#' && s[i+1] == '#'){
                cout << "No" << endl;
                return 0;
            }
        }
        repr(i,b-1,d){
            if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') ok = true;
        }
        cout << (ok?"Yes":"No") << endl;

    }
}