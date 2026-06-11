#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
long long sum=0;
string s;cin>>s;
string x;cin>>x;
if(x==s){
	cout<<0;
}
else{
for(long long i=0;i<s.size();i++){
	if(s[i]!=x[i]){
		sum++;
	}
}
cout<<sum;
}
}