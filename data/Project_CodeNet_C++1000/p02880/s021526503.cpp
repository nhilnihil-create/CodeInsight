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
	int a,b,i,n;
	cin>>n;
	for(i=1;i<10;i++){
		if(n%i==0){
			a=i;
		}
	}
	b=n/a;
	if(b>9){
		cout<<"No"<<nl;
	}
	else{
		cout<<"Yes"<<nl;
	}
	return 0;
}

//Happy Coding........