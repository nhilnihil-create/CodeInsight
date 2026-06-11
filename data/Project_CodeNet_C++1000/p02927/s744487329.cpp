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
int main()
{
	int m,d;cin>>m>>d;
	int ans = 0;
	for(int t=1;t<=m;t++){
		for(int i=2;i<=9;i++)
		for(int j=2;j<=9;j++){
			int v = i*10+j;
			if(v<=d&&i*j==t){
				ans++;
//				cout<<"!"<<i<<" "<<j<<" "<<t<<endl;
			}
		}
	} 
	cout << ans << endl;
}
