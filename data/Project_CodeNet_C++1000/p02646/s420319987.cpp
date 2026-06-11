#include <iostream>
//#include <cstdlib>

using namespace std;


int main(){
	long long a,b,v,w,t;
	cin >> a >> v >> b >> w >> t;
	if (w - v == 0){
	 cout << "NO";
	 return 0;
	}
    if (a < b){
		if ((double)(a-b)/(w-v) <= t && (double)(a-b)/(w-v) >= 0) 
			cout << "YES";
		else cout<< "NO";
    }else{
    	if ((double)(a-b)/(v-w) <= t && (double)(a-b)/(v-w) >= 0) 
			cout << "YES";
		else cout<< "NO";
    }
	//system("PAUSE");
	return 0;
}