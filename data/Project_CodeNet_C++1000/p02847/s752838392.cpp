#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
	
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	
	int a=0,b=28;
	string in;
	
	cin >> in;
	
	if(in=="SAT"){
		a=27;
	}else if(in=="SUN"){
		a=21;
	}else if(in=="MON"){
		a=22;
	}else if(in=="TUE"){
		a=23;
	}else if(in=="WED"){
		a=24;
	}else if(in=="THU"){
		a=25;
	}else if(in=="FRI"){
		a=26;
	}
	
	cout << (b-a) << endl;
	
return 0;
}
