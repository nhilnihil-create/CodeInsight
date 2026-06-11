#include "bits/stdc++.h"

using namespace std;

int main (){
	int a,b;
while(cin >> a >> b){
	if(a == 0 && b == 0) break; 
	for(int i = 1;i <= a;i++){
		if(i % 2 == 1){
			for(int x = 1;x <= b;x++){
				if(x % 2 == 1) cout <<"#";
				else cout << ".";
			}
		}else{
			for(int y = 1;y <= b;y++){
				if(y % 2 == 1)cout << ".";
				else cout << "#";
			}
		}
		cout << endl;

		}

	cout << endl;

}


return 0;
}