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



void solve() {
        
      ll n;
      cin >> n;
      
      ll type1ma = small;
      ll type1mi = big;
      ll type2ma = small;
      ll type2mi = big;
      
      for(ll i = 1; i <= n; i++) {
            ll a, b;
            cin >> a >> b;
            type1ma = max(type1ma, (a + b));
            type1mi = min(type1mi, (a + b));
            type2ma = max(type2ma, (a - b));
            type2mi = min(type2mi, (a - b));
      }
      
      cout << max(abs(type1ma - type1mi), abs(type2ma - type2mi)) << endl;
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
