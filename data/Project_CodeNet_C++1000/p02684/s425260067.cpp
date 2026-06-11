#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector <string> vs;

#define forl(i,a,b) for (ll i = a; i < b; i++)
#define rfor(i,b,a) for (int i = b; i >= a; i--)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define sumup(x) accumulate(x.begin(), x.end(), 0)
#define PI 3.141592653589793238
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin>>n>>k;
    unordered_map <ll,ll> a;
    ll t;
    forl(i,1,n+1) {
        cin>>t;
        a[i] = t;
    }
    map <ll,bool> visited;
    vector <ll> rset;
    if(k<=n) {
        ll j=1;
        forl(i,1,k+1) {
            j = a[j];
        }
        cout<<j<<"\n";
    }
    else {
        ll j=1;
        forl(i,1,k+1) {
            if(!visited[j]) {
                visited[j] = true;
                j = a[j];
            }
            else {
                k -= i;
                t = j;
                j = a[j];
                while(j!=t) {
                    rset.pb(j);
                    j = a[j];
                }
                rset.pb(j);
                k = k % (rset.size());
                cout<<rset[k]<<"\n";
                break;
            }
        }
    }
}