#include<iostream>

const int MAX_N = 1 << 18, INF = 1 << 24;

class SegmentTree{
public:
	SegmentTree(int _n){
		n = 1;
		while(n < _n)n *= 2;
		for(int i=0;i<2*n-1;i++){
			data[i] = 0;
		}
	}

	void add(int k, int a){
		k += n - 1;
		data[k] = a;
		while(k > 0){
			k = (k-1) / 2;
			data[k] = data[k*2+1] + data[k*2+2];
		}
	}

	int calculate(int a, int b){
		return _calculate(a, b, 0, 0, n);
	}
private:
	int data[MAX_N];
	int n;
	int _calculate(int a, int b, int k, int l, int r){
		if(r <= a || b <= l)return 0;

		if(a <= l && r <= b)return data[k];
		else{
			int l_child = _calculate(a, b, 2*k+1, l, (l+r) / 2),
				r_child = _calculate(a, b, 2*k+2, (l+r) / 2, r);
			return l_child + r_child;
		}
	}
};

int main(){
	int n, k;
	while(std::cin >> n >> k, n){
		SegmentTree st(n);
		for(int i=0;i<n;i++){
			int a_i;
			std::cin >> a_i;
			st.add(i, a_i);
		}

		int res = -INF;

		for(int i=0;i+k-1<n;i++){
			res = std::max(res, st.calculate(i, i+k));
		}

		std::cout << res << std::endl;
	}
}