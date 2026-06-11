#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3+7;
int c[N];
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a,b;
	cin>>n>>a>>b;
	for(int i = 1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int dis = 0;
			if(j<=a) dis = j-i;
			else if(i>=b) dis = j-i;
			else if(i>=a&&j<=b) dis = min(j-i,b-j+1+i-a);
			else if(i>=a&&i<=b&&j>=b) dis = min(j-i,i-a+1+j-b);
			else if(i<=a&&j>=a&&j<=b) dis = min(j-i,b-j+1+a-i);
			else if(i<=a&&j>=b) dis = j-i-(b-a)+1;
			c[dis]++; 
		}
	}
	for(int i=1;i<n;i++){
		cout<<c[i]<<endl;
	}
}