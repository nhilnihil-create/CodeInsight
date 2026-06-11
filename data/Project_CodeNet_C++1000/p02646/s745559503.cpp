#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long long a,v,b,w,t;
	cin>>a>>v>>b>>w>>t;
  	string ans = "NO";
  	long long distance = abs(a-b);
  	long long speed = v-w;
    if(distance<=speed*t){
    	ans="YES";
    }
  
	cout<<ans<<endl;
}
