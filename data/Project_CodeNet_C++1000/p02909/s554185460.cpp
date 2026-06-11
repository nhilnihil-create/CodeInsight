#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
	
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	
	string a;
	
	cin >> a;
	
	if(a=="Sunny"){
		cout << "Cloudy" << endl;
	}else if(a=="Cloudy"){
		cout << "Rainy" << endl;
	}else{
		cout << "Sunny" << endl;
	}
	
return 0;
}
