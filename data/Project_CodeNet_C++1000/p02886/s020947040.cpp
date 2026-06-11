// AUTHOR : Kishan Srivastav
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define in freopen("input.txt", "r", stdin)
#define out freopen("output1.txt", "w", stdout)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main() {
	ios
#ifndef ONLINE_JUDGE
	in;
	out;
#endif
	int n;
	cin>>n;
	int d[n];
	for (int i = 0; i < n; i++){
		cin>>d[i];
	}
	int sum = 0;
	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; j++){
			sum = sum + (d[i]*d[j]);
		}
	}
	cout<<sum<<endl;
}