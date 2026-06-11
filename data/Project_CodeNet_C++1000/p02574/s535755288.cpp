#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef set<int> si;
typedef set<ll> sll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

const double pi = acos(-1.0);
const long long INF = 2e18;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define in insert
#define endl "\n"

#define sqr(a) ((a) * (a))
#define jor(a) !(a&1)// jor means EVEN number
#define bjor(a) (a&1)// bjor means ODD number

#define all(a)  a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr)) //memset only for -1 and 0
//fill(a, a+n, 5) //fill for any value

#define for0(i,b) for(int i=0;i<(b);i++)
#define for1(i,b) for(int i=1;i<=(b);i++)
#define forab(i,a,b) for(int i=(a);i<=(b);i++)
#define forba(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fileRead freopen("input.txt", "r", stdin);
#define fileWrite freopen("output.txt", "w", stdout);

void print(int a[], int n){ // for testing or debugging
    for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
}

//-------------------------------------------------------------------\\

si mainset;

si findPrimeFactors(int n)
{
    si s;

    while (n%2== 0) s.in(2), n = n/2;

    for (int i = 3; i*i <= n; i = i+2)
    {
        while (n%i == 0)
        {
            s.in(i);
            n = n/i;
        }
    }

    if (n > 2) s.in(n);

    return s;
}

int main()
{
    
    int n;
    cin>>n;
    int a[n];
    for0(i,n) cin>>a[i];

    bool no=0;
    for0(i,n){
        si s = findPrimeFactors(a[i]);
        for(auto t: s){
            if(mainset.count(t)) {no=1; break;}
            mainset.in(t);
        }
        if(no) break;
    }

    if(no){
        int gcd = a[0];
        for1(i,n-1) gcd = __gcd(gcd,a[i]);
        if(gcd==1) cout<<"setwise coprime";
        else cout<<"not coprime";
    }
    else cout<<"pairwise coprime";
}
