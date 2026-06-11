#include <bits/stdc++.h>


using namespace std;

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()


void go(){
   int l,r,D;cin>>l>>r>>D;
   int ans=0;
   for(int i=l;i<=r;i++) if(i%D==0) ans++; 
   cout << ans;
}
int main(){
   
   fastio();
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}


