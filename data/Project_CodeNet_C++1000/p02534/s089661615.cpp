#include<bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ff first
#define ss second
#define mod 998244353 
#define inf 4e18
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define mx 500005


int main() {
	fast;
	string str = "ACL";
	int k; cin >> k;
	while (k-1 != 0) {
		string str2 = "ACL";
		str.append(str2);
		k--;
	}
	cout << str << endl;
}