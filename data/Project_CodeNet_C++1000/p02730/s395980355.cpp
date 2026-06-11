#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define Rep(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
bool palin(string s,int l,int r){
	while(l<r){
		if(s[l]!=s[r])
			return false;
		l++;
		r--;

	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE    
		freopen("input.txt", "r", stdin);     
		freopen("output.txt", "w", stdout);
	#endif

//----------------------------------------------------//
string s;
cin>>s;
int n = s.length();
bool x = palin(s,0,(n-1)/2-1);
bool y = palin(s,0,n-1);
if(x&&y){
	cout<<"Yes";
}
else{
	cout<<"No";
}





 






	#ifndef ONLINE_JUDGE
   		cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif

return 0;
}

