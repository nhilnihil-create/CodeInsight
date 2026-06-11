#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int arr[26];
	string s;
	cin>>s;
	memset(arr,0,sizeof(arr));
	for(long long int i=0;i<s.size();i++){
		int index=s[i]-'A';
		arr[index]++;
	}
	long long int c=0;
	for(long long int i=0;i<26;i++){
		if(arr[i]==2){
			c++;
		}
	}
	if(c==2){
		cout<<"Yes\n";
	}
	else{
		cout<<"No";
	}
	return 0;
}