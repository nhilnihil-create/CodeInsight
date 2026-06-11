#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int mod=1e9+7;
string s;
int n;
int main(){
	 cin>>n>>s;
 	for(int i=0;i<s.size();i++){
 		s[i]=char((((s[i]-'A')+n)%26)+'A');
 	}
 	cout<<s;
 }