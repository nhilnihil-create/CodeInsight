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
int main(){
	vector<int>q;
	loop(i,1,10000000){
		int tmp=i*(i+1)*(i+2)/6;
		if(tmp>1000000)break;
		q.pb(tmp);
	}
	vector<int>out(1000010);
	rep(i,1000010)out[i]=inf;
	out[0]=0;
	rep(i,q.size())loop(j,q[i],1000010)out[j]=min(out[j],out[j-q[i]]+1);
	
	vector<int>out2(1000010);
	rep(i,1000010)out2[i]=inf;
	out2[0]=0;
	rep(i,q.size()){
		if(q[i]%2==0)continue;
		loop(j,q[i],1000010)out2[j]=min(out2[j],out2[j-q[i]]+1);
	}
	int n;
	while(cin>>n,n)cout<<out[n]<<" "<<out2[n]<<endl;
}