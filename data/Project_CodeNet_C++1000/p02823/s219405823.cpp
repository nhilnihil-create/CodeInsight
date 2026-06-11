#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

int main()
{
   ll N,A,B;cin>>N>>A>>B;
   ll ans;
   ll mid;
   ll m;
   
   if ((B-A)%2==0 && B-A>1)
   {
     //cout<<"--"<<endl;
     ans = abs(A-B)/2;
     cout<<ans<<endl;
     return (0);
   }
   else if ((B-A)%2==1 && B-A>1)
   {
     //cout<<"=="<<endl;
     ans = min(A-1,N-B)+1+(B-A-1)/2;
     cout<<ans<<endl; 
     return (0);
   }
  else if (B-A==1)
  {
    m = min(A-1,N-B);
    cout<<m+1<<endl;
    return (0);
  }
}