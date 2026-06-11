#include <iostream>
#include <vector>
#define MAX_SIZE 51

long long int max_score = 0;
int n, m, q;
std::vector<int> a(MAX_SIZE), b(MAX_SIZE), c(MAX_SIZE), d(MAX_SIZE);
std::vector<int> A(11, 1);


// 条件を満たす組み合わせを全探索
void tree_search(int depth){
	long long int score = 0;
	if(depth > n) return;
 	for(int i = 0; i < q; i++)
		if(A[b[i]-1] - A[a[i]-1] == c[i])
		       score += d[i];
	// std::cout << A[0] << A[1] << A[2] << std::endl;

	if(max_score < score) max_score = score;
	// std::cout << score << std::endl;

	
	for(int i = A[depth-1]; i <= m; i++){
		A[depth] = i;	
		tree_search(depth+1);
	}

	return;
}


int main(void){
	std::cin >> n >> m >> q;	

	for(int i = 0; i < q; i++)
		std::cin >> a[i] >> b[i] >> c[i] >> d[i];
	
	tree_search(1);
	std::cout << max_score << std::endl;
	
	return 0;
}
