#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;



 
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   	int n,i,j,t;
   	cin>>n;
   	int c1,c2,c3,c4;
   	c1=c2=c3=c4=0;
   	string s;
   	while(n--){
   		cin>>s;
   		if(s[0]=='A')c1++;
   		if(s[0]=='W')c2++;
   		if(s[0]=='T')c3++;
   		if(s[0]=='R')c4++;

   	}
   	cout<<"AC x "<<c1<<"\nWA x "<<c2<<"\nTLE x "<<c3;
   	cout<<"\nRE x "<<c4;
	
	
 
 
 
 
 
 
 
	return 0;
}