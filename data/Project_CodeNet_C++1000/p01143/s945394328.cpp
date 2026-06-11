#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<S<<endl
using namespace std;


int main(){
	int N,M,P;
	while(cin>>N>>M>>P,N){
		int a,sum=0,win;
		REP(i,0,N){
			cin>>a;
			if(i+1==M) win=a;
			sum+=a*100;
		}
		sum*=100-P;
		sum/=100;
		if(win==0) cout<<"0"<<endl;
		else cout<<sum/win<<endl;
	}
	return 0;
}