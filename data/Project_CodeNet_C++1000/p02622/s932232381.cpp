#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;



 
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   	int n,i,j;
   	string s,t;
   	cin>>s>>t;
   	int cnt(0);
   	for(i=0;i<s.size();i++){
   		if(s[i]!=t[i])cnt++;
   	}
   	cout<<cnt;
	
	
 
 
 
 
 
 
 
	return 0;
}