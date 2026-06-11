#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

using namespace std;


void autoinput()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

#define ll long long
#define scan(x) scanf("%lld ",&x)
#define pb push_back
#define mp make_pair
#define make_edge(xx,yy) v[xx].pb(yy);v[yy].pb(xx)
#define debug(a) cout << #a << ": " << a << endl
#define pp(a,b) push_back(make_pair(a,b))
#define ff first
#define ss second
#define tff get<0>
#define tss get<1>
#define ttt get<2>
#define mt make_tuple
#define eps 0.0000001
#define sz size()
const ll mod = 998244353;
long double gammay = 0.5772156649015328606065120;




//PBDS
/*
tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update> Data[40];
*/



/*
ordered_set X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5
*/

 //priority_queue<int, vector<int>, std::greater<int> > first;

ll gcd(ll a, ll b)
{
    if(a<b)
        swap(a,b);
    if(b==0)
        return a;
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){

  return (a*b)/__gcd(a,b);
}

ll bigmod(ll N,ll P)
{
    if(P==0) return 1;
    if(P%2==0)
    {
        ll ret=bigmod(N,P/2);
        return ((ret%mod)*(ret%mod))%mod;
    }
    else return ((N%mod)*(bigmod(N,P-1)%mod))%mod;

}
bool isPrime(ll x)
{
    if(x<=1)
        return 0;
    if(x<=3)
        return 1;
    if(x%2==0)
        return 0;
    for(ll i = 3; i*i<=x;i+=2)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}

ll modInverse(ll a, ll m)
{
    return bigmod(a, m-2);
}

ll arr[1000005];

void makeNthRow(ll n){
    ll custom[20];
    ll i=0;
    n--;
    ll m = n;
    while(n){
        custom[i++]=n%2;
        n/=2;
    }
    n=m;
    arr[0]=1;
    arr[n]=1;
    for(i=1;i<n;i++){
        ll p = i;
        ll st = 0;
        ll fl = 1;
        while(p){
            ll x = p%2;
            if(x == 1 && custom[st]==0)
            {
                fl=0;
                break;
            } 
            p/=2;
            st++;
        }
        arr[i]=fl;
    }

}

ll barr[1000006];


int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifdef LOCAL
        autoinput();
    #endif
    ll i,j,k,l,m,n;
    cin >> n;
    string s; 
    cin >> s;
    ll fl=0;
    for(i=0;i<n;i++){
        barr[i] = s[i]-'1';
        if(barr[i]==1){
            fl=1;
        }

    }
    makeNthRow(n);
    ll ans = 0;
    if(fl){
        for(i=0;i<n;i++){
            barr[i]%=2;
            if(arr[i] && barr[i]){
                ans^=barr[i];
            }
        }
        cout << ans << endl;


    }
    else{
        for(i=0;i<n;i++){
            if(barr[i]==2)
                barr[i]--;
            if(arr[i] && barr[i]){
                ans^=barr[i];
            }
        }
        if(ans){
            ans++;
        }
        cout << ans << endl;
    }

}
