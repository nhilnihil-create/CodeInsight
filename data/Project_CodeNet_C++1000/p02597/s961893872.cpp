#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>v1,v2;
	int n;
	string s;
	cin >> n >> s;
	for(int i=0;i<n;i++){
		if(s[i]=='W'){
			v1.push_back(i+1);
		}
		else{
			v2.push_back(i+1);
		}
	}
	int cnt1 = 0,cnt2 = 0;
	for(auto it:v1){
		if(it<n-v1.size()+1)cnt1++;
	}
	for(auto it:v2){
		if(it>v2.size())cnt2++;
	}
	cout << min(cnt1,cnt2)<< "\n";
}
