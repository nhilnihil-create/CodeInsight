#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int main()
{
	for(int h;cin>>h && h;){
		vector<vector<int>> a(h,vector<int>(5));
		rep(i,h) rep(j,5) cin>>a[i][j];
		int res=0;
		for(;;){
			int add=0;
			for(auto& b:a) for(int j=0;j<5;){
				if(b[j]==0){
					j++;
					continue;
				}
				int k=j;
				while(k<5 && b[k]==b[j]) k++;
				if(k-j>=3){
					add+=(k-j)*b[j];
					fill(begin(b)+j,begin(b)+k,0);
				}
				j=k;
			}
			if(add==0) break;
			res+=add;
			rep(i,5) for(int j=h,k=h;k--;)
				if(a[k][i]) swap(a[--j][i],a[k][i]);
		}
		cout<<res<<endl;
	}
}