#include<cstdio>
#include<vector>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	bool a[N];
	for (int i = 0; i < N; ++i){
		int tmp;
		scanf("%d", &tmp);
		a[i] = tmp == 1;
	}
	for (int i = N; i > 0; --i){
		for (int j = 2; j <= N/i; ++j){
			a[i - 1] ^= a[i*j - 1];
		}
	}
	vector<int> ans;
	for (int i = 0; i < N; ++i){
		if(a[i]) ans.push_back(i + 1);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i){
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}