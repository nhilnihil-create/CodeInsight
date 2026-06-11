#pragma GCC optimize("Ofast")
#include  "bits/stdc++.h"
using namespace std;
#define I_AM_SPEED  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define printclock  cerr <<"Time : "<<(double)clock()/(double)CLOCKS_PER_SEC<<" sec\n";
#define mp(a , b)   make_pair(a , b)
#define eb(a)       emplace_back(a)
#define SZ(n)       ((int)(n).size())
#define all(n)      (n).begin(), (n).end()
#define anal           '\n'
#define mod         1000000007
#define fst         first
#define sec         second
#define pr(n)       cerr << n  << " ";
#define pfor(a)       for(auto (w) : (a)) pr(w)
//const double PI = acos(-1.0);
typedef long long ll;
typedef unsigned long long ull;

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-



//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
      
int main(){
I_AM_SPEED;
#ifndef ONLINE_JUDGE  
        freopen("input.in", "r", stdin);
        freopen("output.in", "w", stdout);
#endif 

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
      
     
       vector<int> v(3);

       for(int i = 0; i < 3; i++) cin >> v[i];
        int k;
        cin >> k;
        if(v[0] < v[1] && v[1] < v[2]){
           cout << "Yes\n";
        }
        else{
          bool ans = false;
             while(k--){
                  if(v[2] <= v[1] || v[2] <= v[0]){
                       v[2] *= 2;
                  }
                  else if(v[1] <= v[0]){
                        v[1] *= 2;
                  }
                  if(v[0] < v[1] && v[1] < v[2]){
                    cout << "Yes\n";
                    ans = true;
                    break;
                 }
            
             }
             if(!ans){
                 cout << "No\n";
             }

        }


        

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//printclock; 
return  0 ;      
}        



      