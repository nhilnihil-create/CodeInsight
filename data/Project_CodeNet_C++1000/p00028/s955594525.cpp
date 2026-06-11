#include <iostream>
#include <cmath>
#include <algorithm>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

int main(void){
	int a[101]={} , n;
	while(cin>>n){
		a[n]++;
	}
	n = 0;
	FOR(i,1,100){
		if(a[i]>n)
			n=a[i];
	}
	FOR(i,1,100){
		if(a[i]==n)
			cout << i << endl;
	}


	return 0;
}