#include<bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define ll long long int
int main(){
	AC
	string a,b;
	cin>>a>>b;
	int ans=100000;
	for(int i=b.size()-1;i<a.size();i++){
		int j=i;
		int k=b.size()-1;
		int countt=0;
		if(a[j]!=b[k])countt++;
		while(k-- && j--){
			if(a[j]!=b[k])countt++;
		}
		ans=min(countt,ans);
	} 
	cout<<ans<<endl;
} 
