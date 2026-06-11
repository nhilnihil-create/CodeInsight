#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(int num)
{
	for(int i=2; i*i<=num; i++){
		if(num%i==0)
		 return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	cin>>num;
	for(int i=num; ; i++){
		if(isprime(i)){
		 cout<<i;
		 return 0;
	    }
		 
	}
	return 0;
}