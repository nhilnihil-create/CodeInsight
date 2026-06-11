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
int n;
cin>>n;
ll a[n],b[n];
for(int i=0;i<n;i++){
	ll x,y;
	cin>>x>>y;
	a[i]=(x-y);
	b[i]=(x+y);
}
sort(a,a+n);
sort(b,b+n);
cout<<max(abs(a[0]-a[n-1]),abs(b[0]-b[n-1]))<<endl;
return 0;
}