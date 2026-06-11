#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll x;
	cin>>x;
	for(int i=1;i<=360;i++){
		if(i*x%360==0){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
