#include <iostream>
using namespace std;

#define REP(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

int main(void){
	REP(i,1,10)REP(j,1,10){
		cout<<i<<"x"<<j<<"="<<i*j<<endl;
	}

	return 0;
}