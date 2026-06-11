#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <utility>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define INF 1000000001
#define mod 1000000007
using namespace std;

int main(){
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	int q;
	cin>>q;
	vector<int> ans(q);
	//vector<char> x,y;
	/*if(q>21){
		x.resize(101);
		y.resize(101);
	}*/
	string x,y;
	vector<vector<int>> a;
	rep(aaa,q){
		cin>>x;
		cin>>y;
		int xs=x.size();
		int ys=y.size();
		a.resize(xs+1);
		rep(i,xs+1){
			a[i].resize(ys+1);
		}
		rep(i,xs+1){
			rep(j,ys+1){
				if(i==0 || j==0){
					a[i][j]=0;
				}else if(x[i-1]==y[j-1]){
					a[i][j]=a[i-1][j-1]+1;
				}else{
					a[i][j]=max(a[i-1][j],a[i][j-1]);
				}
			}
		}
		ans[aaa]=a[xs][ys];
	}
	rep(i,q){
		cout<<ans[i]<<endl;
	}
	

}