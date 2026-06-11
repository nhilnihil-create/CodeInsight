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
	int n,k;
	cin>>n>>k;
	int count=0;
	int a[n];
	for (int i = 0; i < n; i++){
		cin>>a[i];
		if(a[i] >= k){
			count++;
		}
	}
	cout<<count<<endl;


}