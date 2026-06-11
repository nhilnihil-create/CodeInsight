#include <iostream>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a[4], b[4];
	
	while(cin >> a[0]){
		for(int i = 1; i < 4; ++i){
			cin >> a[i];
		}

		for(int i = 0; i < 4; ++i){
			cin >> b[i];
		}

		int hit = 0;
		for(int i = 0; i < 4; ++i){
			if(a[i] == b[i]){
				hit++;
			}
		}

		int blow = 0;
		for(int i = 0; i < 4; ++i){
			for(int j = 0; j < 4; ++j){
				if(i != j && a[i] == b[j]){
					blow++;
				}
			}
		}

		cout << hit << " " << blow << endl;
	}

	return 0;
}