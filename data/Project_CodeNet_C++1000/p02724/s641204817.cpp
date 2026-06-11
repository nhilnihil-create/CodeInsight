#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll money;
	cin>>money;
	ll ha = 0;
	ha += money/500*1000;
	money %= 500;
	ha += money/5*5;
	cout<<ha<<endl;
}