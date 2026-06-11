#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
typedef pair<ll,ll>pll;
const  ll MAX=100000000;
int main()
{


ll n;

cin>>n;


ll l=n/1000;

if(n%1000)l++;

l=l*1000;


cout<<l-n<<endl;





}

