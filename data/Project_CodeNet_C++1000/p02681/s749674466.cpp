#include <bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n1 = s1.length();
	int n2 = s2.length();
	if (n1 = n2 + 1){
		for (int i = 0; i<s1.size(); i++){
			if (s1[i] != s2[i]){
				cout<<"No";
				return 0;
			}
		}
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}