#include <bits/stdc++.h>
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()

using namespace std;


int main(){
	int x , y , z; cin >> x >> y >> z;
	int k ; cin >> k;
	if(y > x && z > y){
		cout << "Yes\n";
		return 0;
	}
	for(int i = 0 ; i <= 10; i++){
		for(int j = 0 ; j <= 10 ; ++j){
			for(int l = 0 ; l <= 10; ++l){
				if(i + j + l <= k && (x * (1 << i)) < (y *(1 << j)) && (y * (1 << j)) < (z * (1 << l))){
					cout << "Yes\n";
					return 0;
				}
			}
		}
	}
	cout << "No\n";
	return 0;
}