#include <bits/stdc++.h>
using namespace std;

#define ris   return *this
#define tmplt template<class T
#define dbgo  debug& operator<<
tmplt > struct rge { T b, e; };
tmplt > rge<T> range(T i, T j) { return rge<T>{i, j}; }
struct debug {
#ifdef LOCAL
~debug(){cerr<<endl;}
tmplt > dbgo(T x){cerr<<boolalpha<<x;ris;}
tmplt, class C > dbgo(pair<T, C> x){ris<<"("<<x.first<<", "<<x.second<<")";}
tmplt > dbgo(rge<T> x){*this<<"[";for(auto it=x.b;it!=x.e;it++){*this<<", "+2*(it==x.b)<<*it;}ris<<"]";}
tmplt > dbgo(vector<T> x){ris<<range(x.begin(),x.end());}
#else
tmplt > dbgo(const T&){ris;}
#endif
};
#define nav(...) << "[ " << #__VA_ARGS__ ": " << (__VA_ARGS__) << " ] "
using ll = long long;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ford(i, n) for(int i = n-1; i >= 0; i--) 

template<typename T> 
void min_self(T& a, T b) { 
   a = min(a, b); 
}
template<typename T>
void max_self(T& a, T b) { 
   a = max(a, b); 
}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   for(int rep = 0; rep < k; rep++) {
      vector<int> b(n);
      for(int i = 0; i < n; i++) {
         int d = a[i];
         int L = max(0, i - d), R = min(n-1, i + d);
         ++b[L];
         if(R < n-1) {
            --b[R+1];
         }
      }
      bool anything = false;
      int prefix_sum = 0;
      for(int i = 0; i < n; i++) {
         prefix_sum += b[i];
         if(prefix_sum != a[i]) {
            a[i] = prefix_sum;
            anything = true;
         }
      }
      if(!anything) {
         debug() nav(rep);
         break;
      }
   }
   for(int x : a) {
      cout << x << ' ';
   }
   cout << '\n';
}















// Author: blondie
