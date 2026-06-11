#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int a,b,ans = 1; cin>>a>>b;
	if(b==1)cout<<0<<endl;
	else{
		int aux = a;
		while(a<b){
			a+=aux;
			a--;
			ans++;
		}
		cout<<ans<<endl;
	}
}
