# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// int = ll;

int main(){	
	
ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);	

	ll a,b;
	
	cin >> a >> b;
	
	if(a<=b){
		cout << "unsafe" << endl;
	}else{
		cout << "safe" << endl;
	}

return 0;	
}
