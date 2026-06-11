#include <iostream>
using namespace std;
int n;
string s;
int cnt=1;
int main(){
	cin>>n>>s;
	
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1])
			continue;
		cnt++;
	}
	
	cout<<cnt;
	return 0;
}
