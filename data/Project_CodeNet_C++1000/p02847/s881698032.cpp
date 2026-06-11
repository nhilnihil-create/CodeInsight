#include <bits/stdc++.h>
using namespace std;

signed main(){
	string S;
	cin >> S;
	if(S == "SUN"){
		printf("7\n");
	}
	else if(S == "MON"){
		printf("6\n");
	}
	else if(S == "TUE"){
		printf("5\n");
	}
	else if(S == "WED"){
		printf("4\n");
	}
	else if(S == "THU"){
		printf("3\n");
	}
	else if(S == "FRI"){
		printf("2\n");
	}
	else{
		printf("1\n");
	}
	return 0;
}