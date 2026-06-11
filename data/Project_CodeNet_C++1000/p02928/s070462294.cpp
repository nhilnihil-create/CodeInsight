#include <bits/stdc++.h>

using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long
const long long INF=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;


int32_t main() {
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    
    ini(n);
    ini(n1);
    vi V(n);
    int pref[n];
    fill(pref,pref+n,0);
    int ato[n];
    fill(ato,ato+n,0);
    FOR(i,0,n){
        in(V[i]);
    }
    FOR(i,0,n){
        FOR(i1,0,i){
            if(V[i1]<V[i])pref[i]++;
        }
        FOR(i1,i+1,n){
            if(V[i1]<V[i])ato[i]++;
        }
    }
    int tmp = 0;
    int mo = 1000000007;
    FOR(i,0,n){
        tmp+=(pref[i]*((((n1-1)*n1)/2)%mo))%mo;
        tmp+=(ato[i]*((n1*(n1+1)/2)%mo))%mo;
    }
    tmp = tmp%mo;
    out(tmp);
    
    
    
    
    
    
    return 0;
}
