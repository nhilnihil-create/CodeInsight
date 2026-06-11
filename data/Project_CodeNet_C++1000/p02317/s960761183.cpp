#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e9;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
int LIS(vi in){//Longest Increasing Subsequence
	int n=in.size();
	int r=1;
	vi out(n+1,inf);
	rep(i,n){
		*lower_bound(all(out),in[i])=in[i];
	}
	return lower_bound(all(out),inf)-out.begin();
}
int main(){
	int n;
	cin>>n;
	vi in(n);
	rep(i,n)cin>>in[i];
	cout<<LIS(in)<<endl;
}