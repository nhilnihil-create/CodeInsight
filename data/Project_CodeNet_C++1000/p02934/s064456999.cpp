#include <bits/stdc++.h> 
using namespace std; 
#define rep(i,a,b)		for(int i=a;i<=b;i++)


int main() 
{ 

	ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,n;
    double ans;
    cin>>n;
    rep(i,1,n)
    {
    	cin>>a;
    	ans += (double)1/a;
    }
    ans=1/ans;
    cout << setprecision(16) << ans << endl;
} 
