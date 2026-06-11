#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

#define M 1000000007

ll fastexp(ll a, ll b){
   ll ae=a, ans=1;
   for(int i=0; i<64; i++){
      if((b>>i)&1) ans=(ans*ae)%M;
      ae=(ae*ae)%M;
   }
   return ans;
}

int main(){
   int n, k;
   cin>>n>>k;

   ll cn[100001];
   for(int g=k; g>=1; g--){
      cn[g]=fastexp(k/g, n);
      for(int i=g*2; i<=k; i+=g) cn[g]=(cn[g]-cn[i]+M)%M;
   }

   ll cnt=0;
   for(int i=1; i<=k; i++) cnt=(cnt+(i*cn[i])%M)%M;

   cout << cnt << endl;
   return 0;
}
