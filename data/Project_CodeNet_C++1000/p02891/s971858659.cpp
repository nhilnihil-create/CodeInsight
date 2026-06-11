#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
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
#define iter vector< int >::iterator
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

const int N=1e7+7;
const int inf=1e18+1e9;
const int mod=998244353;
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

main ()
{
    ios;
    string s;
    int k;
    cin>>s>>k;
    vector< pair<int,int> >a;
    int cur=0;
    for (int i=0;i<s.size();++i){
        if (i && s[i]!=s[i-1]){
            a.pb({s[i-1],cur});
            cur=1;
        }
        else {
            ++cur;
        }
    }
    a.pb({s.back(),cur});
    if (a.size()==1){
        int ans=(int)s.size()*k;
        cout<<ans/2<<endl;
        exit(0);
    }
    if (a[0].ff!=a.back().ff){
        int res=0;
        for (int i=0;i<a.size();++i){
            res+=a[i].ss/2;
        }
        int ans=res*k;
        cout<<ans<<endl;
    }
    else {
        int res=0;
        for (int i=1;i<(int)a.size()-1;++i){
            res+=a[i].ss/2;
        }
        int f=a[0].ss+a.back().ss;
        int ans=res*k+(k-1)*(f/2);
        ans+=a[0].ss/2+a.back().ss/2;
        cout<<ans<<endl;
    }
}
