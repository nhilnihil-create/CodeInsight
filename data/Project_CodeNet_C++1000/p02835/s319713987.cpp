# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// int = ll;

int main(){
	
ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	
	ll a[2];	
	
	cin >> a[0] >> a[1] >> a[2];
	
	if((a[0]+a[1]+a[2])>=22){
		cout << "bust" << endl;
	}else{
		cout << "win" << endl;
	}
	
return 0;	
}
