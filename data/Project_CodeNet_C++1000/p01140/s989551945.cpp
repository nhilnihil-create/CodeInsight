#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<time.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e8;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
int main(){
	int n,m;
	while(cin>>n>>m,n+m){
		vi a(n),b(m);
		rep(i,n)cin>>a[i];
		rep(i,m)cin>>b[i];
		int ma=-1;
		map<int,int>ina,inb;
		rep(i,n){
			int sum=0;
			loop(j,i,n){sum+=a[j];ina[sum]++;}
			ma=max(ma,sum);
		}
		rep(i,m){
			int sum=0;
			loop(j,i,m){sum+=b[j];inb[sum]++;}
			ma=max(ma,sum);
		}
		int co=0;
		loop(i,1,ma+1){co+=ina[i]*inb[i];}
		cout<<co<<endl;
	}
}