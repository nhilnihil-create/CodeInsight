
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


ll lcm(ll a,ll b)
{
    return(a*b/__gcd(a,b));
}
int main()
{

ll a,b;
cin>>a>>b;

cout<<lcm(a,b)<<endl;

 return 0;
}
