#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
int main(){
	string str;
	cin>>str;
	int ans = 0;
	for(int i = 0 ; i < str.length()-1 ; i++){
		 if(str[i] == 'P' && str[i+1] == 'D'){
		 	        ans++;
		 }
	}
	for(int i = 0 ; i < str.length() ; i++){
		 if(str[i] == 'D' || str[i] == '?'){
		 	str[i] = 'D';
		 	 ans++;
		 }
	}
	cout<<str<<endl;
	//cout<<ans<<endl;
}