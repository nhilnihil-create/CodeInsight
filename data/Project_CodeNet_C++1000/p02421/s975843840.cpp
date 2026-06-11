#include <iostream>
#include <string>
using namespace std;

int main(){
	
	int n, m, taro = 0, hanako = 0;
	int i, j;
	string st, sh;
	
	cin >> n;
	
	for(i = 0; i < n; ++i){
		cin >> st >> sh;
		
		if(st.size() > sh.size()) m = st.size();
		else m = sh.size();
		
		for(j = 0; j < m; ++j){
			
			if(st[j] < sh[j]){
				hanako += 3;
				break;
			}
			else if(st[j] > sh[j]){
				taro += 3;
				break;
			}
			
			if(j == m-1){
				if(st.size() > sh.size()) taro += 3;
				else if(st.size() < sh.size()) hanako += 3;
				else{
					++taro;
					++hanako;
				}
			}
		}
	}
	
	cout << taro << " " << hanako << endl;
	
	return 0;
}