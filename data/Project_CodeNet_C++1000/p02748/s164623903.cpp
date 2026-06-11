#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
   int A, B, M;
   cin>>A>>B>>M;
   int a[100000], b[100000];
   rep(i, A) cin>>a[i];
   rep(i, B) cin>>b[i];
   int mn=INT_MAX;
   rep(i, M){
      int x, y, c;
      cin>>x>>y>>c; x--; y--;
      mn=min(mn, a[x]+b[y]-c);
   }
   int mna=INT_MAX, mnb=INT_MAX;
   rep(i, A) mna=min(mna, a[i]);
   rep(i, B) mnb=min(mnb, b[i]);
   mn=min(mn, mna+mnb);
   cout << mn << endl;
   return 0;
}
