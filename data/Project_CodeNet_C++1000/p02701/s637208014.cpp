#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
map<string,int> x;
int main()
{
	ll n,sum=0;
	string a;
	cin >> n;
	while(n--){
		cin >> a;
		if(x[a]==0){
			sum++;
			x[a]++;
		}
	}
	cout << sum << endl;
}