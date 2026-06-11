#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define Rep(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
ll fact(int x){
	if(x==0)
		return 0;
	return (x*(x-1))/2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE    
		freopen("input.txt", "r", stdin);     
		freopen("output.txt", "w", stdout);
	#endif

//----------------------------------------------------//
 int n,m;
 cin>>n>>m;
 ll x = fact(n);
 ll y = fact(m);
 cout<<x+y;





 






	#ifndef ONLINE_JUDGE
   		cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif

return 0;
}

