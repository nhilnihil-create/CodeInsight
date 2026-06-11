#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;

string S;
LL MOD=1e9+7;
LL large[100011];
LL small[100011];

int main(){
	cin>>S;
	large[0]=2;
	small[0]=1;
	REP(i,S.size()-1){
		if(S[i+1]=='1'){
			large[i+1]=2*large[i];
			large[i+1]%=MOD;
			small[i+1]=large[i]+small[i]*3;
			small[i+1]%=MOD;
		}else{
			large[i+1]=large[i];
			small[i+1]=small[i]*3;
			small[i+1]%=MOD;
		}
		//cout<<S[i+1]<<" "<<large[i+1]<<" "<<small[i+1]<<endl;
	}
	cout<<(large[S.size()-1]+small[S.size()-1])%MOD<<endl;
	return 0;
}