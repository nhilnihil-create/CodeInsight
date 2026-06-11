#include <iostream>
using namespace std;

int main(){
	int n, m;
	char aft[130];
	bool exi[130];
	char a, b;
	
	while(true){
		cin >> n;
		
		if(n == 0) break;
		
		for(int i = 0; i < 130; i++) exi[i] = false;
		
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			aft[(int)a] = b;
			exi[(int)a] = true;
		}
		
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> a;
			
			if(exi[(int)a]) cout << aft[(int)a];
			else cout << a;
		}
		cout << endl;
	}
	
	return 0;
}