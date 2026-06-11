#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define v vector<int>
#define mi map<int,int>
#define mc map<char,int>

//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int k;
	cin>>k;
	string s,s1="";
	cin>>s;
	int i,n=s.length();
	if(n>k){
	for(i=0;i<k;i++){
		s1.push_back(s[i]);
		}
		for(i=0;i<3;i++)s1.push_back('.');
	}
	else{s1=s;}
		cout<<s1 <<"\n";
}