#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb               push_back
#define sz(c)            (int)c.size()
#define len(c)           (int)c.length()
#define vec              vector
#define int              long long int
#define mp(x,y)          make_pair(x,y)
#define all(c)           c.begin(), c.end()
#define rall(c)          c.rbegin(), c.rend()
#define trav(a,i)        for(auto& i: a)
#define loop(n,i,a)      for(int i=a;i<n;i++)
#define invect(v,n)       for(int i=0;i<n;i++ ){int arb;cin>>arb;v.pb(arb);}
#define inset(s,n)        loop(n,i,0){int aset;cin>>aset;s.insert(aset);}
#define display(c)        trav(c,i) cout<<i<<" ";
#define F                 first
#define S                 second
#define pii               pair<int,int>
#define pp               pop_back
#define endl              "\n"
#define copy(a,b)         copy(all(a),back_inserter(b));
#define intersect(a,b,w)    set_intersection(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
#define union(a,b,w)      set_union(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
#define diff(a,b,w)       set_difference(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
#define symdiff(a,b,w)    set_symmetric_difference(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
//int m=10000009;
//int arr[100000];
#define M                   1000000007
#define mm  998244353  
//set<int> st;
signed main()
{
    fast
    int a[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int n;
    cin>>n;
    cout<<a[n-1];
}