#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

int gcd(int a,int b){


	if(a==0||b==0){
		return a+b;
	}
	return gcd(b%a,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	long long int a,b;
	cin>>a>>b;
	int k = gcd(a,b);

	cout<<(a*b*1ll)/k;



}

