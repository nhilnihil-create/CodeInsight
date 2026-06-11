#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<utility>
#include<queue>
#include<stdio.h>
//#include<sys/time.h>
#include<random>
#include<fstream>
#define INF 2000000000
using namespace std;
typedef std::pair<int,int> P;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define min(X,Y) (((int)(X)<(int)(Y))?(X):(Y))
#define max(X,Y) (((int)(X)>(int)(Y))?(X):(Y))
int n,ans,cnt;
signed main(){
	cin>>n;
	rep(i,n){
		int a,b;
		cin>>a>>b;
		if(a==b)cnt++;
		else{
			ans=max(ans,cnt);
			cnt=0;
		}
	}
	ans=max(ans,cnt);
		if(ans>=3)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
}
