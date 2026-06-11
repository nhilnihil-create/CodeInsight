#include <bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<ll, ll>
#define pb push_back
#define rep0(i, n) for(ll i = 0;i<n;i++)
#define rep1(i, n) for(ll i = 1;i<n;i++)
#define all(v) v.begin(),v.end()
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;

vector<bool> arr(N, false);

bool factorise(int a){
    bool flag = true;
    for(int i=2; i*i<=a; i++){
        if(a%i == 0){
            if(arr[i] || arr[a/i]){
                arr[i] = true;
                arr[a/i] = true;
                flag = false;
                return flag;
            }
            else{
                arr[i] = true;
                arr[a/i] = true;
            }
        }
    }
    return flag;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i=0; i<n; i++){
        cin >> v[i];
        arr[v[i]] = true;
    }
    bool ok = 1;
    ll a = v[0];
    for(ll i=1; i<n; i++){
        a = __gcd(a, v[i]);
    }
    for(ll i=0; i<n; i++){
        if(!factorise(v[i])){
            ok = 0;
            break;
        }
    }
    if(ok){
        cout << "pairwise coprime";
    }
    else if(a == 1){
        cout << "setwise coprime";
    }
    else{
        cout << "not coprime";
    }
}
 
int main()
{
    fast;
    solve();
    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    return 0;
}