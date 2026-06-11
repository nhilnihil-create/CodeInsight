#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prime;
vector<int>::iterator it,it2;
int main(){
	long i,j,n;
	char buf[120], p;
	for(i=2;i<123457*2;i++){
		for(it=prime.begin();it!=prime.end();it++)if(i%*it==0)break;
		if(it==prime.end()) prime.push_back(i);
	}
	while(cin>>n,n){
		it = lower_bound(prime.begin(), prime.end(), n+1);
		it2 = lower_bound(prime.begin(), prime.end(), 2*n+1);
		cout << it2-it << endl;
	}
	
	return 0;
}