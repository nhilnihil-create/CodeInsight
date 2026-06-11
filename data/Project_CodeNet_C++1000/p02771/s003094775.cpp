#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if(a==b&&b!=c){
		cout << "Yes" << endl;
	}else if(b==c&&c!=a){
		cout << "Yes" << endl;
	}else if(c==a&&a!=b){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}