#include<bits/stdc++.h>


//      DEEP


using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fwd(i,a,n) for(int i=a;i<=n;i++)
#define bak(i,a,n) for(int i=a;i>=n;i--)
#define all(v) v.begin(),v.end()
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef set<int> si;
const ll mod = 1e9 + 7;
ull power(ull x,ull y){
   if(y==0) return 1;
   else{
     if(y%2==0) return power(x*x,y/2);
     else return x*power(x*x,(y-1)/2);
   }
}
ull gcd(ull x,ull y){
   if(y==0)return x;
   return gcd(y,x%y);
}
int main(){
    boost;
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--){
      ll a,b;
      cin>>a>>b;
      ll x=b-a+1;
      ll y=b+a-1;
      for(int i=x;i<=y;i++)cout<<i<<" ";
      cout<<endl;
    }
}
/* Be careful about integer ranges;
   Check the corner cases before submitting.
*/


