// AUTHOR : Kishan Srivastav
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main() {
	ios
#ifndef ONLINE_JUDGE
	in;
	out;
#endif
	int n;
	cin>>n;
	double count = 1 ;
	for (int i = 2; i <= n; i++){
		if( i % 2 != 0 ){
			count++;
		}
	}
	double ans;
	ans = (count/n);
	cout<< fixed <<setprecision(10) <<ans<<endl;

}