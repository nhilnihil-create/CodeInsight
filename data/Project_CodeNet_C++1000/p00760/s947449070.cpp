#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;

LL check(int a,int b, int c){
	a--;
	b--;
	c--;
	LL now=0;
	REP(i,a){
		REP(j,10){
			if(j%2==0){
				now+=20;
			}else{
				if(i%3==2){
					now+=20;
				}else{
					now+=19;
				}
			}
		}
	}
	REP(i,b){
		if(i%2==0){
			now+=20;
		}else{
			if(a%3==2){
				now+=20;
			}else{
				now+=19;
			}
		}
	}
	now+=c;
	return now;
}

int main(){
	cin>>N;
	LL now=check(1000,1,1);
	REP(k,N){
		int y,m,d;
		cin>>y>>m>>d;
		//cout<<"aa"<<check(y,m,d)<<endl;
		cout<<now-check(y,m,d)<<endl;
	}
}
