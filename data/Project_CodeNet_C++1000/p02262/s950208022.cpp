#include <iostream>
#include <vector>


std::vector<int> insertion_Sort(std::vector<int>, int);
std::vector<int> shell_Sort(std::vector<int>);
int cnt = 0;
std::vector<int> G;

int main(int argc, char const *argv[]){
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i){
		std::cin >> A[i];
	}

	std::vector<int> v = shell_Sort(A);
	std::cout << G.size() << std::endl;

	for (int i = G.size()-1; i >=0; --i){
		std::cout << G[i] << " ";
		if(i<G.size()-1) std::cout << " ";		
	}
	std::cout << std::endl;
	std::cout << cnt << std::endl;

	for (int i = 0; i < v.size(); ++i){
		std::cout << v[i] << std::endl;
	}

	return 0;
}

std::vector<int> insertion_Sort(std::vector<int> A, int G){
	for (int i = G; i < A.size(); ++i){
		int buff = A[i];
		int j = i - G;
		while( j>=0 && A[j]>buff ){
			A[j+G] = A[j];
			j -= G;
			cnt++;
		}
		A[j+G] = buff;
	}
	return A;
}

std::vector<int> shell_Sort(std::vector<int> A){
	int h = 1;
	while(A.size()>=h){
		G.push_back(h);
		h = 3 * h + 1;
	}

	for (int i=G.size()-1; i >= 0; --i){
		A = insertion_Sort(A, G[i]);
	}
	return A;
}

