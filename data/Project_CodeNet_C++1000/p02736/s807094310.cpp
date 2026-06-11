#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(a) a.begin(),a.end()
#define ull unsigned long long
#define y1 asjdlfaskavslbcjasndscf
#define endl '\n'
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define iter vector< pair<int,int> >::iterator
#define iter1 multiset<int>::iterator
#define int long long
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template<class T>
using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd1(chrono::steady_clock::now().time_since_epoch().count());

//find_by_order
//order_of_key

const int N=1e6+7;
const int inf=1e18+1e9;
int mod=2;
const ld eps=1e-9;

//const int MAX_MEM=1e8;
//int mpos=0;
//char mem[MAX_MEM];
//
//inline void * operator new(size_t n){
//    char *res=mem+mpos;
//    mpos+=n;
//    assert(mpos<=MAX_MEM);
//    return (void*)res;
//}
//
//inline void operator delete(void *) {}

int f[N];
int a[N];

int st(int n,int k)
{
    int res=1;
    while(k){
        if (k%2==1){
            res=(res*n)%mod;
        }
        n=(n*n)%mod;
        k/=2;
    }
    return res;
}

int kol(int l,int r,int x)
{
    int f=r/x-(l-1)/x;
    return f;
}

int C(int n,int k)
{
    int res=0;
    int st=2;
    while(st<=n){
        res+=kol(n-k+1,n,st);
        res-=kol(1,k,st);
        st*=2;
    }
    if (res)return 0;
    return 1;
}

int solve(vector<int>p)
{
//    for (int i=0;i<p.size();++i){
//        cout<<p[i]<<' ';
//    }
//    cout<<endl;
    int m=p.size();
    bool f1=1;
    vector<int>p1=p;
    for (int i=0;i<p.size();++i){
        if (p[i]!=0)f1=0;
    }
    if (f1)return 0;
    for (int i=0;i<p.size();++i){
        p[i]%=2;
    }
    int res=0;
    for (int i=0;i<m;++i){
        if (C(m-1,i)==1){
            res^=p[i];
        }
    }
    if (res==1){
        return 1;
    }
    else {
        bool g=0;
        for (int i=0;i<p.size();++i){
            if (p[i]==1)g=1;
        }
        if (g){
            return 0;
        }
        for (int i=0;i<p1.size();++i){
            p1[i]/=2;
        }
        return solve(p1)*2;
    }
}

main ()
{
    ios;
    f[0]=1;
    for (int i=1;i<N;++i){
        f[i]=(f[i-1]*i)%mod;
    }
    int n;
    string s;
    cin>>n>>s;
    for (int i=0;i<n;++i){
        a[i]=s[i]-'0';
    }
    vector<int>c;
    for (int i=0;i<=n-2;++i){
        c.pb(abs(a[i]-a[i+1]));
    }
//    for (int i=0;i<c.size();++i){
//        cout<<c[i]<<' ';
//    }
//    cout<<endl;
    if (c.size()==1){
        cout<<c[0]<<endl;
    }
    else {
        cout<<solve(c)<<endl;
    }
}
