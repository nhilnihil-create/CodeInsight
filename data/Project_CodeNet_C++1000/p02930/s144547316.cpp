#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
#define int long long
using namespace std;
int lv[514][514];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ci = i, cj = j;
			for(int k=1;k<=9;k++){
				if( (ci%2)+(cj%2)==1 ){
					cout<<k<<" ";
					k=100;
				}
				else{
					ci /= 2;
					cj /= 2;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}