#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	for(int i=0;i<n;){
		if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
			cnt++;
			i += 3;
		}else{
			i++;
		}
	}
	cout << cnt << endl;
}
