#include <bits/stdc++.h>
using namespace std;
int main(){
	string n;
	int i,boi=0;
	cin>>n;
	for (i=0;i<=n.size()-1;i++){
		boi=boi+n[i]-48;
	}
	if (boi%9==0){cout<<"Yes";
	}
	else cout<<"No";
	return 0;
}
