#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL sum;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b,c,d;
	cin >> n;	
	for(a=1;a<=n;a++)
		for(b=1;b<=n;b++)
			for(c=1;c<=n;c++)
				d=gcd(a,b),d=gcd(c,d),sum+=d;
	cout << sum << endl;	
	return 0;
}