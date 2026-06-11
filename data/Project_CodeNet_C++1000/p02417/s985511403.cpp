#include<bits/stdc++.h>
using namespace std;
 
int main(){
	vector<int>a(26);
	string b;
	while(cin>>b){for(int c=0;c<b.length();c++){
		if(b[c]>='a'&&b[c]<='z')a[b[c]-97]++;
		else if(b[c]>='A'&&b[c]<='Z')a[b[c]-65]++;
		}
			}
					for(int d=0;d<26;d++){
			cout<<char(d+'a')<<" : "<<a[d]<<endl;  }
}