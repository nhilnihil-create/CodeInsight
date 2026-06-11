
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{

ll n ;
cin>>n;

ll ans =0;
for(ll i = 0 ; i <=n;i++)
  if(i%3&&i%5)
  {
     // cout<<i<<endl;
      ans+=i;
  }




cout<<ans<<endl;


 return 0;
}
