#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

int main() {
	int N; cin>>N;
	int wgt[N];
	double diff = std::numeric_limits<double>::infinity();
	int differ;
		int sum1=0;
			int sum2=0;
	for(int a=0;a<N;a++){
		cin>>wgt[a];
	}
	for(int T=1;T<N;T++){
		for(int a=0;a<=T;a++){
			sum1+=wgt[a];
		}
		for(int b=N-1;b>T;b--){
			sum2+=wgt[b];
		}
		
		 differ=sum1-sum2;
		if(differ<=diff){
			diff=abs(differ);
		}
		sum1=0;
		sum2=0;
	}
	if(diff==0){
		printf("0\n");
	}
	else {
		cout<<diff<<endl;
	}
	return 0;
}