#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	char* P = (char*)calloc(N+1, sizeof(char));
	char* Q = (char*)calloc(N+1, sizeof(char));
	int p, q;
	for(int i = 0; i < N; i++){
		cin >> P[i];
	}
	p = atoi(P);
	for(int i = 0; i < N; i++){
		cin >> Q[i];
	}
	q = atoi(Q);
	
	vector<int> a(N);
	vector<int> nums;//順列が入る
	for(int i = 0; i < N; i++) a.at(i) = i+1;
	/*順列を生成には、next_permutationを使えばよい*/
	do{
		char* num_c = (char*)calloc(N+1, sizeof(char));
		for(int i = 0; i < N; i++){
			num_c[i] = a.at(i) + 48;
		}
		nums.push_back(atoi(num_c));
	}while(next_permutation(a.begin(), a.end()));
	
	
	int a_num=0, b_num=0;
	for(int i = 0; i < nums.size(); i++){
		if(nums.at(i) == p) a_num = i;
		if(nums.at(i) == q) b_num = i;
	}
	cout << abs(a_num-b_num) << endl;
	
}
