#include<bits/stdc++.h>
using namespace std;
set<string>s;
int main(){
	int n;
	cin>>n;
	string a;
	int ans=0;
	for(int i=1;i<=n;i++){
	    cin>>a;
	    if(!s.count(a)){
	       s.insert(a); 
	       ans++;
	    }
	}
	cout<<ans<<endl;
}
