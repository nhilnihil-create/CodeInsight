# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// int = ll;

int main(){	
	
ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);	

	ll a,b;
	
	cin >> a >> b;
	
	if(a<=9&&b<=9){
		cout << (a*b) << endl;
	}else{
		cout << -1 << endl;
	}

return 0;	
}
