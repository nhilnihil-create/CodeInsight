#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF = 1e6+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	
	string s;
	cin >> s;
	long long k;
	cin >> k;
	s+=s;
	
	bool f=true;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]==s[i+1])continue;
		f=false;
		break;
	}
	if(f){
		long long ans=s.size()/2*k/2;
		cout << ans << endl;
		return 0;
	}
	
	string t;
	for(int i=0;i<s.size();i++){
		t+=s[i];
		if(s[i]==s[i+1]){
			t+='*';
			i++;
		}
	}
	
	//cout << t << endl;

	long long cnt_first=0;
	for(int i=0;i<t.size()/2;i++){
		if(t[i]=='*')cnt_first++;
	}
	
	long long cnt_second=0;
	for(int i=t.size()/2;i<t.size();i++){
		if(t[i]=='*')cnt_second++;
	}
	
	long long ans=cnt_first+(k-1)*cnt_second;
	
	cout << ans << endl;
	return 0;
}
