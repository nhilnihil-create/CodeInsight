#include <bits/stdc++.h>


using namespace std;


#define ll long long
#define mk make_pair
#define pb push_back
#define ff first
#define sc second
#define all(x) x.begin(), x.end()
#define sz(x) (x).size()

ll gcd(ll a, ll b);

ll sum(int n);

int len(int n){
   string nn=to_string(n);
   return nn.size();
}
void go(){
   int n;cin>>n;
   int ans=0;
   for(int i=1;i<=n;i++){
      if(len(i)%2==1) ans++;
   }

   cout << ans;
}
int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}

ll gcd(ll a, ll b){     
   if(b == 0) return a;
   
   return gcd(b, a % b);
}

ll sum(int n){                
   if(n == 0){
      return n;
   }else{
      return sum(n/10) + n%10;
   }
}
