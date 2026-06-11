# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// int = ll;

int main(){
	
ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	
	ll a,b;
	
	cin >> a >> b;
	
	if(a==1&&b==2){
		cout << 3 << endl;
	}else if(a==2&&b==1){
		cout << 3 << endl;
	}else if(a==1&&b==3){
		cout << 2 << endl;
	}else if(a==3&&b==1){
		cout << 2 << endl;
	}else if(a==2&&b==3){
		cout << 1 << endl;
	}else if(a==3&&b==2){
		cout << 1 << endl;
	}
	
	
	
return 0;	
}
