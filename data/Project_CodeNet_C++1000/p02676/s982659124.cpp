#include <bits/stdc++.h>
//#include "/Users/tania/Downloads/stdc++.h"
using namespace std;
typedef long long int lli;

int main(){
	int n; cin>>n;
	string s; cin>>s;

	if(s.size() <= n)
		cout<<s<<endl;
	else{
		for(int i=0; i<n; i++){
			cout<<s[i];
		}cout<<"..."<<endl;
	}
	return 0;
}