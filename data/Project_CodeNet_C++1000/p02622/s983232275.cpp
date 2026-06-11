#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
	string s1,s2;
	int s=0;
	while(getline(cin,s1)){
		getline(cin,s2);
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]) s++;
		}
		cout<<s<<endl;	
		s=0;
	}
	return 0;
}