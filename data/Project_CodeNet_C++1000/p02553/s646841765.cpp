/******************************************
* AUTHOR : SOMU KUMAR *
* INSTITUTION : IIT BHUBANESWAR *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//code here...............//
ll a,b,c,d;
cin>>a>>b>>c>>d;
ll ans=max(a*c,max(a*d,max(b*c,b*d)));
cout<<ans<<endl;
return 0;
}