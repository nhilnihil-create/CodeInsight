#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);

    rep(i,n){
        cin >> a[i];
    }

    ll count=0;
    rsort(a);
    count+=a[0];
    int k=1;
    int i=1;
    while(i<n-1){
        rep(j,2){
            count+=a[k];
            ++i;
            if(i==n-1){
                break;
            }
        }
        ++k;
        
    }
    cout << count << endl;
}