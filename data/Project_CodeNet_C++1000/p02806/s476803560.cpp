#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 233;
map<string,int> id;
int a[maxn];
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s>>a[i];
		id[s] = i;
	}
	string t;cin>>t;
	int k = id[t];
	int sum = 0;
	for(int i=k+1;i<=n;i++)sum+=a[i];
	cout << sum << endl; 
}
