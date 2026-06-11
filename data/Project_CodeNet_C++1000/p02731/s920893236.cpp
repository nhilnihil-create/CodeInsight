#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define  ff     first
#define  ss     second
#define  pb     push_back
#define  all(x) (x).begin(), (x).end()
#define  rep(i,a,b) for(int i=a ; i<b ; ++i)
#define  deb(x) cout << #x << " - " << x << "\n";
#define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  D2(x)  cout << "[" << #x << ": "; for(auto it:x) cout << it << " "; cout << "]\n"; 
#define  D2p(x)	cout << #x << " ~ [ "; for(auto n: x) cout << n.first << "-" << n.second << " / "; cout << "]" << "\n";
#define  ps(x,y) fixed<<setprecision(y)<<x

int main() {
    IOS;
    long double l; cin >> l;
    long double x = (l / 3); 
    cout << ps(x*x*x,12);
}