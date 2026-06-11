#include <bits/stdc++.h>
using namespace std;
string s,t;
int sl,tl;
int main(){
	//注意对于sl的长度特殊判断！ 
	cin>>s>>t;
	sl = s.length();
	tl = t.length();
	int ans = 1946081700;
	for(int i=0;i+tl<=sl;i++){
		int tm = 0;
		for(int j = 0;j<tl;j++){
			if(s[i+j]!=t[j]) tm++;
		}
		ans = min(tm,ans);
	}
	cout<<ans;
} 