#include <iostream>
using namespace std;
 
int main() {
	string s;
	cin >> s;
	int nextL=0,lastR=0,ans[200010]{0};
	for(int i=0;i<s.size();i++){
		while(s[nextL] != 'L' || nextL < i){
			nextL++;
		}
		if(s[i] == 'R'){
			lastR = i;
			if((nextL-i)%2 == 0){
				ans[nextL]++;
			}else{
				ans[nextL-1]++;
			}
		}else{
			if((i-lastR)%2 == 0){
				ans[lastR]++;
			}else{
				ans[lastR+1]++;
			}
		}
	}
	for(int i=0;i<s.size();i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}