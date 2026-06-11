#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	while(1){
		int n; cin >> n;
		if(!n) break;
		vector<string> f(n);
		for(int i=0; i<n; i++){
			cin >> f[i];
		}
		int ans = 0;
		bool on = false;
		for(int i=0; i<n-1; i++){
			if(on){
				if((f[i] == "ld" && f[i+1] == "rd") || (f[i] == "rd" && f[i+1] == "ld")){
					ans++;
					on = !on;
					i++;
				}
			} else{
				if((f[i] == "lu" && f[i+1] == "ru") || (f[i] == "ru" && f[i+1] == "lu")){
					ans++;
					on = !on;
					i++;
				}
			}
		}
		cout << ans << endl;
	}
}
