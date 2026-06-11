#include <iostream>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int N;
	int M;
	cin >> N >> M;
	vector<int>A(M);
	int total = 0;
	for(int i = 0;i<M;i++){
		cin >> A[i];
		total += A[i];
	}
	
	if(total>N){
		std::cout << "-1" <<std::endl;
	}else{
		std::cout << N-total <<std::endl;
	}
	
	return 0;
}
