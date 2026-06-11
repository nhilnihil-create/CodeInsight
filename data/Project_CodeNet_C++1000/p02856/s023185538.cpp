#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=32e4;

int d[N],p[20][20],v[20][20];
ll c[N],ans;

ll cal(int d,ll c){
	ll a=0;
	if(d==0){
		ans+=c-1;
		return 0;
	}
	while(c){
		if(c%10){
			if(a)ans++;
			a=a+v[d][c%10];
			if(a>9){
				a=a%10+a/10;
				ans++;
			}
			ans+=p[d][c%10];
		}
		c/=10;
		ans+=c*p[d][10];
	}
	return a;
}
ll cal(ll d){
	while(d>9){
		d=d%10+d/10;
		ans++;
	}
	return d;
}
int main(){
	ios::sync_with_stdio(0);
	for(int j=1;j<=10;j++)p[0][j]=j-1;
	for(int i=1;i<10;i++){
		int x=i;
		for(int j=1;j<=10;j++){
			p[i][j]=p[i][j-1];
			while(x>9){
				x=x%10+x/10;
				p[i][j]++;
			}
			v[i][j]=x;
			x=x*10+i;
		}
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>d[i]>>c[i];
		d[i]=cal(cal(d[i],c[i]));
	}
	for(int i=1;i<m;i++){
		d[i]+=d[i-1]*10;
		d[i]=cal(d[i]);
	}
	cout<<ans;
	return 0;
}