#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>

#define rep(i,s,N) for(int i=s; i<N; ++i)
#define N_MAX 1000000

template<typename T>
void print(T *x, int n, std::string sep=" ") {
	rep(i,0,n) {
		if (i==0) {
			std::cout << x[i];
			continue;
		}
		std::cout << sep << x[i];
	}
	std::cout << std::endl;
}

// 6:15
// 6:49 うまくいきそうな感触, algorithm の直観的な理解
// 大きく動かす, 比較対象位置は粗から密へ, O(log(n))で. n = 2^k, log(n) = k log(2) 
// nが奇数の場合どうするか.
// 例: n=5
// 3 1 4 5 2
// 3 - 5
// 1 - 2
// 4 - ?
// 比較しない要素が出るのはまずい. devide and conquer であるから, 各分割で漏れなく処理する必要がある.
// (n-1) / 2 を開始index かつ, interval lengthとすればよい.
//

template<typename U>
int sort_by_insertion(U *x, int n, int g) {
	int cnt = 0;
	for (int i=g; i<n; ++i) {
		U v = x[i];
		int j = i-g;
		while (j>=0 && x[j] > v) {
			x[j+g] = x[j];
			j = j-g;
			cnt++;
		}
		x[j+g] = v;
	}
	return cnt;
}

template<typename U>
std::tuple<int, std::vector<int> > sort_by_shell(U *x, int n) {
	std::vector<int> G;
	int cnt = 0;
	//int g = n / 2; // たぶんここがなにが想定と違うらしい.
	int g = n;
	while (g > 0) {
		G.push_back(g);
		g /= 2;
	}
	//print(G.data(), G.size());
	for (int i=0; i<G.size(); ++i) {
		g = G[i];
		cnt += sort_by_insertion(x, n, g);
	}
	std::tuple<int, std::vector<int> > ret = std::make_tuple(cnt, G);
	return ret;
}

using namespace std;

int main() {
	int N;
	cin >> N;
	int values[N_MAX];
	rep(i,0,N) {
		scanf("%d", &values[i]);
	}
	auto ret = sort_by_shell(values, N);
	int cnt = get<0>(ret);
	vector<int> G = get<1>(ret);
	
	cout << G.size() << endl;
	print(G.data(), G.size());
	cout << cnt << endl;
	print(values, N, "\n");
}

