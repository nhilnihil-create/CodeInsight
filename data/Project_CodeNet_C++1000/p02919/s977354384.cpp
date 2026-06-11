#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define res(n) resize(n)
#define rev(v) reverse(v.begin(),v.end())
#define sor(v) sort(v.begin(),v.end())
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pq priority_queue
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;



int main()
{
    int N;cin>>N;
    vi a(N);
    in(N,a);
    rep(i,N) a[i]--;
    vi idx(N);
    rep(i,N) idx[a[i]] = i;
    ll ans = 0;
    set<int> s;
    
    for (int x = N-1; x >= 0; x--) {
        int i = idx[x];
        ll c = 0;
        
        s.insert(i);
        vi l(2,-1),r(2,N);
        auto it = s.find(i);
        rep(j,2){
            if(it == s.begin()) break;
            --it;
            l[j] = *it;
        }
        it = s.find(i);
        rep(j,2){
            ++it;
            if(it == s.end()) break;
            r[j] = *it;
        }
        
        vi ls(2);
        ls[0] = -l[0]+i; ls[1]=l[0]-l[1];
        vi rs(2);
        rs[0] = r[0]-i; rs[1]=r[1]-r[0];
        
        c = (ll)ls[0]*rs[1] + (ll)ls[1]*rs[0];
        
        ans += c*(x+1);
    }
    out(ans);
    

    return 0;
}
