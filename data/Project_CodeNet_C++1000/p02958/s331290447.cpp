#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int p[n];
	
	int w_count = 0;
	
	for(int i = 0; i < n; i++){
		cin >> p[i];
		if(p[i] != i+1){
			w_count++;
		}
	}
	
	if(w_count <= 2) cout << "YES";
	else cout << "NO";
	cout << endl;
	
}