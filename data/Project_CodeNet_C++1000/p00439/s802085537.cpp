#include<iostream>

const int MAX_N = 1 << 17, INF = 1 << 24;
class BIT{
public:
	BIT(int _n)
		:n(_n){
		std::fill(bit, bit+n, 0);
	}
	int sum(int i){
		int s = 0;
		while(i > 0){
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	int add(int i, int x){
		while(i <= n){
			bit[i] += x;
			i += i & -i;
		}
	}
private:
	int bit[MAX_N], n;
};

int main(){
	int n, k;
	while(std::cin >> n >> k, n){
		BIT b(n+1);
		for(int i=1;i<=n;i++){
			int a_i;
			std::cin >> a_i;
			b.add(i, a_i);
		}

		int res = -INF;
		for(int i=1;i+k-1<=n;i++){
			res = std::max(res, b.sum(i+k-1) - b.sum(i-1));
		}

		std::cout << res << std::endl;
	}
}