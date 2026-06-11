/*I wanna be the very best, like no one ever was...*/

#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define mem(a, b) memset(a, (b), sizeof(a))
#define rep(i, j, k) for (int i = j ; i < k ; ++i)
#define rrep(i, j, k) for (int i = j; i > k; --i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(i, a) for(auto i: a)
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define debug(a) cout << #a << ": " << a << endl
#define Flag(n) cout << "here " << n << endl
#define mp make_pair
#define pb push_back

#define endl '\n';
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll POSITIVE_INFINITY = 9223372036854775807;
const ll NEGATIVE_INFINITY = -9223372036854775807;
const ll MOD = 1000000007;
const ld PI = acos(-1.0);
 


int main() {
    io;
    ll n ;
    cin>>n;
   vector<ll > t(n);
   vector<string> s(n); 
    rep(i,0,n){
        cin>>s[i]>>t[i];
    }

    string x;
    cin>>x;
    auto it = find(s.begin(),s.end(), x);
    int index = it -s.begin();
    ll sum = accumulate(t.begin()+index+1, t.end(),0);
    cout<<sum;

  
  

 
 
 
    
 
    return 0;
}