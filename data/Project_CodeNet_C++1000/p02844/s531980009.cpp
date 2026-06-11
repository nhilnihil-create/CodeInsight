#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans=0;
	for(int i=0;i<1000;i++){
		string t;
		if(i>=0 && i<10){
			t+="00";
		}else if(i>=10 && i<100){
			t+='0';
		}
		t+=to_string(i);
		int now=0;
		for(int j=0;j<n;j++){
			if(t[now]==s[j]){
				now++;
				if(now==3){
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << endl;		
	return 0;
}