#pragma GCC optimize("Ofast")
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
	string s;
	cin >> s;
	int ans=0;
	string now="";
	string pre="";
	for(int i=0;i<s.size();i++){
		if(pre==""){
			pre=s[i];
			ans++;
			continue;
		}else{
			now+=s[i];
		}
		if(now!=pre){
			pre=now;
			ans++;
			now="";
		}
	}
	cout << ans << endl;		
	return 0;
}
