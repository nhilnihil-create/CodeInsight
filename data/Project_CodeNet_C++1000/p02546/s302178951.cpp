#include<bits/stdc++.h>
using namespace std;
#define inf (1<<30)
bool prime(int x){
	if(x<2)return 0;
	for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	cout<<s;
	if(s[s.size()-1]=='s')cout<<"es";
	else cout<<'s'; 
	return 0;
}
