#include<iostream>
#include<string>
using namespace std;

int main(){
	int n,i,ans=0;
	string s;
	char h=0;

	cin>>n>>s;

	for(i=0;i<n;i++){

		if(s[i]!=h){
			ans++;
		}

		h=s[i];
	}

	cout<<ans<<endl;

	return 0;
}