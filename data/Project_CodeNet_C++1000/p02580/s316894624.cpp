#include <bits/stdc++.h>
using namespace std;


#define ll long long int
#define ld long double
#define mod 1000000007
#define big 1e18+100000000
#define small -big
#define pb push_back



template <typename T>

void prarr(T a)
{
     cerr << "[ ";
     
     for(auto i : a){
         cerr << i << " ";
     }
     
     cerr << "]" << endl;
}


#define trace(...) _er(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>

void _er(const char* name, Arg1&& arg1){
	cerr << "[" << name << " : " << arg1 << "]" << endl;
}

template <typename Arg1, typename... Args>

void _er(const char* names, Arg1&& arg1, Args&&... args){
    
	const char* comma = strchr(names + 1, ',');
	cerr << "[" ; cerr.write(names, comma - names) << " : " << arg1 << "] ";
	_er(comma+2, args...);
}


vector<ll> A[300005];
set<pair<ll, ll> > g;


void solve() {
           
           g.clear();
           
           ll H, W;
           cin >> H >> W;
           
           ll M;
           cin >> M;
           
           for(ll i = 1; i <= W; i++) {
                    A[i].clear();
           }
           
           
           ll row[H + 1] = {0};
           ll column[W + 1] = {0};
           
           for(ll i = 1; i <= M; i++) {
                    ll a, b;
                    cin >> a >> b;
                    row[a]++;
                    column[b]++;
                    A[b].pb(a);
           }
           
           for(ll i = 1; i <= H; i++) {
                g.insert({row[i], i});
           }
           
           ll ma = 0LL;
           
           for(ll i = 1; i <= W; i++) {
                    ll ma1 = 0LL;
                    for(auto it : A[i]) {
                            ma1 = max(ma1, row[it]);
                    }
                    
                    if(A[i].size() >= 1) {
                            ma = max(ma, column[i] + ma1 - 1);
                    }
                    for(auto it : A[i]) {
                            g.erase({row[it], it});
                    }
                   
                    
                    if(g.size() >= 1) {
                            auto it = g.end();
                            it--;
                            ma = max(ma, column[i] + (*it).first);
                    }
                    
                    for(auto it : A[i]) {
                            g.insert({row[it], it});
                    }
               
           }
           
           cout << ma << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   

    int t=1;
    //cin >> t;

    for(int i = 1; i <= t; i++) {  
   
         solve();
    }


    return 0;
        
}
