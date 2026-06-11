#include <bits/stdc++.h> 
using namespace std; 
  
int main()  
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n,x,t;
    cin>>n>>x>>t;
    int T=(n+x-1)/x;
    cout<<T*t;
	return 0;
}