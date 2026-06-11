#include <bits/stdc++.h>

using namespace std;

int main() {
	int A, B, C, K;
	cin>>A>>B>>C>>K;
	
	int sum;
	if(A>=K){
	    sum = K;
	}else if(A < K && K <= (A+B) ){
	    sum = A;
	}else if((A+B) < K && K <= (A+B+C)){
	    sum = A - (K - (A+B));
	}else{
	    sum = 0;
	}
	
	cout<<sum<<endl;
	return 0;
}