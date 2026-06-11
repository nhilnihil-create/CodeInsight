
#include <bits/stdc++.h>
using namespace std;


#define ll long long int
#define ld long double
#define mod 1000000007
#define big 1e18+10
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




vector<ll> A[200005];

void solve() {
    
    
            ll N;
            cin >> N;
            
            for(ll i = 1; i <= N; i++) {
                    A[i].clear();
            }
            
            for(ll i = 1; i <= (N - 1); i++) {
                        ll a, b;
                        cin >> a >> b;
                        A[a].pb(b);
                        A[b].pb(a);
            }
            
            for(ll i = 1; i <= N; i++) {
                    sort(A[i].begin(), A[i].end());
            }
            
            ll c = 1;
            
            ll prev = 1;
            
            for(ll i = N - 1; i >= 1; i--) {
                       
                     
                                ll te = 0;
                                ll now = 1;
                                ll er1 = i;
                                
                                for(auto it : A[i]) {
                                        if(it > i) {
                                             te += ((it - er1) * now);
                                             now--;
                                             er1 = it;
                                        }
                                }
                                te += ((N + 1 - er1) * now);
                                
                                prev += te;
                                c += prev;
                                
                       
                        
                      
            }
            
            cout << c << endl;
            
           
            
           
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   

    int t=1;
   // cin >> t;

    for(int i = 1; i <= t; i++) {  
   
         solve();
    }


    return 0;
        
}
