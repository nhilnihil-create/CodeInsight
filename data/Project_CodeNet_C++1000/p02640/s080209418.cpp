#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;



 
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   	int n,i,j,x,y;
   	cin>>x>>y;
   	int t1=4*x-y,t2=y-2*x;
   	if(t1>=0 && t2>=0 && t1&1^1 && t2&1^1)cout<<"Yes\n";
   	else cout<<"No\n";	
 
 
 
 
 
 
 
	return 0;
}