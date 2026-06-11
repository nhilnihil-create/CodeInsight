#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b;
    int c, d;
    string s;
    
    cin >> a >> s;
    int id = s.find('.');
    string aux = s.substr(0, id);
    c = atoi(aux.data());
    
    aux = s.substr(id+1);
    d = atoi(aux.data());
    
    b = c*100 + d;
    ll ans = b*a/100;
    
    cout << ans << endl;
}
