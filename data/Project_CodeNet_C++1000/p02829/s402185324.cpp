#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	int n[] = {1,1,1};
	n[a-1] = n[b-1] = 0;
	for(int i = 0; i < 3; i++){
		if(n[i] == 1) cout << i+1 << endl;
	}
}