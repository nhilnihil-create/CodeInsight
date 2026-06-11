#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	int a,b,c,k;
	cin >> a >> b >> c >> k;
	int ans = 0;
	for(int i = 0; i < k; i++){
		if(a>0){a--;ans++;}
		else if(b>0)b--;
		else if(c>0){c--;ans--;}
	}
	cout << ans << endl;
}
