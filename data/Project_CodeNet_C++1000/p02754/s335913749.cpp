#include <iostream>
#include <vector>
#include <math.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define PI 3.1415926535897932
using namespace std;

int main(){
	long long N,A,B;
	cin>>N>>A>>B;
	long long M,ans;
	
	if(N>A+B){
		long long SetN = N/(A+B);
		long long Nokori = N%(A+B);
		if(Nokori<=A)M=Nokori;
		if(Nokori>A)M=A;
		ans=M+SetN*A;
	}else if(N<=A+B){
		if(N<=A)ans=N;
		if(N>A)ans=A;
	}

	cout<<ans<<endl;
}