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
	for(int i=1;i<n;i++){
		ans+=n/i;
		if(n%i==0)ans--;
	}
	cout<<ans<<endl;
}
