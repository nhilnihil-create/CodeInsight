#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	cin>>str;
	int m,b;
	while(str!="-"){
		cin>>m;
		int sum=0;
		for(int i=0;i<m;i++){
			cin>>b;
			sum+=b;
		}
		sum%=str.size();
		str=str.substr(sum,str.size()-sum)+str.substr(0,sum);
		cout<<str<<endl;
		cin>>str;
	}
	return 0;
}

