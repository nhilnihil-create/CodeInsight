#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		char ch=s[i];
		for(int j=0;j<n;j++){
			if(ch=='Z'){
				ch='A';
			}
			else{
				ch++;
			}
		}
		cout << ch;
	}
}
