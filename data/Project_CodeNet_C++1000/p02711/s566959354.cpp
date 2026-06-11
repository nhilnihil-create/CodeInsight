#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n;
	cin>>n;
	while(n){
		if(n%10 ==  7){
			cout<<"Yes"<<endl;
			return;
		}
		n = n/10;
	}
	cout<<"No"<<endl;
}
int main()
{

  solve();

return 0;
}

