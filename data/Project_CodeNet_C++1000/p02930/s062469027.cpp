#include<bits/stdc++.h>
using namespace std;
int n,a[1010][1010];
vector<int> v[1010];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		int x=i;
		while (x!=0){
			v[i].push_back(x%2);
			x/=2;
		}
		while (v[i].size()<60) v[i].push_back(0);
		reverse(v[i].begin(),v[i].end());
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=0;k<v[i].size();k++)
				if (v[i][k]!=v[j][k]) a[i][j]=a[j][i]=60-k;
	for (int i=1;i<=n;i++,cout<<endl)
		for (int j=i+1;j<=n;j++)
			cout<<a[i][j]<<' ';
	return 0;
}