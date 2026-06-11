#include <bits/stdc++.h>

using namespace std;

int main(){
	int ans=0;
	string w,t;
	cin>>w;
	for(int i=0;i<w.size();i++) if('A'<=w[i]&&w[i]<='Z') w[i]-=('A'-'a');
	while(1){
		cin>>t;
		if(t=="END_OF_TEXT") break;
		for(int i=0;i<t.size();i++) if('A'<=t[i]&&t[i]<='Z') t[i]-=('A'-'a');
		if(w==t) ans++;
	}
	cout<<ans<<endl;;
	return 0;
}

