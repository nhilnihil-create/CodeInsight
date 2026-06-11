// Starting with the name of Allah

#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define Nayon ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define gcd(a,b)         __gcd(a,b)
#define lcm(a,b)         (a/gcd(a,b))*b


using namespace std;




int main()
{
	Nayon;
	ll i,j,k,n,cnt=0;
	cin>>n;
	ll a[n+1];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				if(a[i]==a[j] || a[i]==a[k] || a[j]==a[k]){
					continue;
				}
				else{
					if(a[i]+a[j]>a[k]){
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt<<nl;
}
