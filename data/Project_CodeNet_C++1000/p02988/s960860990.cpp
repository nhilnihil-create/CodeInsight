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

void go(){
   int n;cin>>n;
   vector<int> nums(n);
   for(int i=0;i<n;i++){
      cin>>nums[i];
   }
   int ans=0;
   for(int i=1;i<n-1;i++){
      int mi=min({nums[i-1], nums[i+1]});
      int ma=max({nums[i-1], nums[i+1]});
      if(nums[i]>=mi&&nums[i]<=ma) ans++;
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
