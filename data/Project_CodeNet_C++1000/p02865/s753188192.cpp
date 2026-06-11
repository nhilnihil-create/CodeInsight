#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main(){
	
	long n,ans;
	cin >> n;
	if(n%2==0){
		ans=(n-1)/2;
	}else{
		ans=n/2;
	}
	cout << ans << endl;
	return 0;
}
