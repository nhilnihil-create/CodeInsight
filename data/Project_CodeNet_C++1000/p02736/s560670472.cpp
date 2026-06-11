#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
string s;
int a[1000001];
int b[1000001];

int c[1000001];
LL num[1000011];

void init(){
	num[0]=0;
	REP(i,1000011){
		if(i==0)continue;
		num[i]=num[i-1];
		int temp=i;
		while(temp%2==0){
			temp/=2;
			num[i]++;
		}
	}
}
int main(){
	cin>>N;
	cin>>s;
	REP(i,N){
		if(s[i]=='1'){
			c[i]=1;
		}else if(s[i]=='2'){
			c[i]=2;
		}else if(s[i]=='3'){
			c[i]=3;
		}
	}
	REP(i,N-1){
		c[i]=abs(c[i]-c[i+1]);
	}
	N--;
	if(N==1){
		cout<<c[0]<<endl;
		return 0;
	}
	bool check=false;
	REP(i,N){
		if(c[i]==1){
			a[i]=0;
			b[i]=1;
			check=true;
		}else if(c[i]==2){
			a[i]=1;
			b[i]=0;
		}else{
			a[i]=0;
			b[i]=0;
			//check=true;
		}
	}
	init();
	LL aa=0;
	REP(i,N){
		if(a[i]==1){
			if(num[N-1]-num[i]-num[N-1-i]==0){
				aa++;
			//					cout<<"+"<<i<<endl;
			}
		}
		
		//cout<<num[N-1]-num[i]-num[N-1-i]<<endl;
	}
	LL bb=0;
	REP(i,N){
		if(b[i]==1){
			if(num[N-1]-num[i]-num[N-1-i]==0){
				bb++;
			}
		}
		//cout<<num[N-1]-num[i]-num[N-1-i]<<endl;
	}
	aa%=2;
	bb%=2;
	if(check){
		aa=0;
	}
	cout<<aa*2+bb<<endl;
}