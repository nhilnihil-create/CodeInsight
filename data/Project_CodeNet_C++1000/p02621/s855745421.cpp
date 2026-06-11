#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define REP(i,a,b) for(ll i=a;i<b;i++)
typedef long long ll;
using namespace std;

void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


int main(){

FAST();

ll n;
  
  cin>>n;
 ll ans=n+(n*n)+(n*n*n);
 cout<<ans<<endl;



return 0;
}