#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{
ll n ;
cin>>n;

ll ans =1000000000001;
for(ll i = 1;i*i<=n;i++)
{
    if(n%i==0)
    ans = min(ans,(i-1)+(n/i-1));
}
std::cout<<ans<<endl;

 return 0;
}
