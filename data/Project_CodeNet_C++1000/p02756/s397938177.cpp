#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define  ff         first
#define  ss         second
#define  pb         push_back
#define  all(x)     (x).begin(), (x).end()
#define  rep(i,a,b) for(int i=a ; i<b ; ++i)
#define  deb(x)     cout << #x << " - " << x << "\n";
#define  IOS        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  D2(x)      cout << "[" << #x << ": "; for(auto it:x) cout << it << " "; cout << "]\n"; 
#define  D2p(x)	    cout << #x << " ~ [ "; for(auto n: x) cout << n.first << "-" << n.second << " / "; cout << "]" << "\n";
#define  ps(x,y)    fixed<<setprecision(y)<<x
 
#define PI 3.141592653589793238462643383279502884L
const ll MOD = 1e9 + 7;
const ll INF = 1000000000;
const ll MAX_N = 4e4 + 10;

 
int main() {
    IOS;
    string s; cin >> s;
    int q,parity = 0,posn; cin >> q;
    char c;
    while(q--){
        int type; cin >> type;
        // deb(type);
        if(type==1) parity++;
        else{
            cin >> posn >> c;
            int sz = s.size();
            if(parity%2){
                if(posn==1) s.insert(sz,1,c);
                else s.insert(0,1,c);
            } else{
                if(posn==1) s.insert(0,1,c);
                else s.insert(sz,1,c);
            }
        }
        // deb(s);
    }
    if(parity%2) reverse(all(s));
    cout << s;
}