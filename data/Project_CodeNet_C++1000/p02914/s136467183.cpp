#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rrep(i,n) for(int i=(n);i>=0;i--)
#define rrepa(i,a,n) for(int i=(n)-1;i>=(a);i--)
#define sortn(a) sort((a).begin(),(a).end())
#define sortr(a) sort((a).begin(),(a).end(),greater<int>())
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

int main(){
    
    int n;
    cin >> n;
    ll ans=0;
    vl a(n);
    rep(i,n){
        cin >> a[i];
        ans ^= a[i];    
    }
    rep(i,n)a[i] &= (~ans);;

    int c=0;
    rrep(i,59){
        repa(j,c,n){
            if(a[j]>>i&1){
                swap(a[c],a[j]);
                rep(k,n){
                    if(k==c)continue;
                    if(a[k]>>i&1){
                        a[k] ^= a[c];
                    }
                }
                c++;
                break;
            }
        }
    }

    ll tmp=0;
    rep(i,c){
        tmp ^= a[i];
    }

    ans += tmp*2; 

    cout << ans << endl;
    
    return 0;
}