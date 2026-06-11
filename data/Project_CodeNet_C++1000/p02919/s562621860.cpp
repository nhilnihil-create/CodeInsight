#include <bits/stdc++.h>
using namespace std;
#define int long long

template<typename M>
struct segment_tree{
	typedef function<M(M, M)> F;
	int size;//2冪
	vector<M> val;//1-indexed
	F f;//結合関数
	M e;//単位元

	segment_tree(int N, vector<M> &data, F f, M e) : f(f), e(e){
		size = 1;
		while(size < N) size *= 2;
		val.assign(2 * size, e);
		for(int i = 0; i < N; i++) val[size + i] = data[i];
		for(int i = N; i < size; i++) val[size + i] = e;
		for(int i = size - 1; i > 0; i--) val[i] = f(val[2 * i], val[2 * i + 1]);
	}

	//k番目の要素をxに変更する
	void update(int k, M x){
		k += size;
		val[k] = x;
		while(k /= 2) val[k] = f(val[2 * k], val[2 * k + 1]);
	}

	//[l, r)の演算の結果を返す
	M query(int l, int r){
		M L = e, R = e;
		for(l += size, r += size; l < r; l /= 2, r /= 2){
			if(l & 1) L = f(L, val[l++]);
			if(r & 1) R = f(val[--r], R);
		}
		return f(L, R);
	}
};




//(int, sum, 0)
int sum(int x, int y){
	return x + y;
}

signed main(){
	int N, i;
	scanf("%lld", &N);
	vector<int> P(N + 2), Pinv(N + 2);
	for(i = 1; i <= N; i++){
		scanf("%lld", &P[i]);
		Pinv[P[i]] = i;
	}
	vector<int> data(N + 2, 0);
	data[0] = 2;
	data[N + 1] = 2;
	segment_tree<int> t(N + 2, data, sum, 0);
	int ans = 0;
	for(i = N; i > 0; i--){
		int j = Pinv[i];
//		printf("(i, j) = (%lld, %lld)\n", i, j);
		int l, h, r;
		int a, b, c;

		l = 0;
		r = j;
		while(r - l > 1){
			h = (l + r) / 2;
			if(t.query(h, j) >= 2){
				l = h;
			}
			else{
				r = h;
			}
		}
		a = l;

		l = 0;
		r = j;
		while(r - l > 1){
			h = (l + r) / 2;
			if(t.query(h, j) >= 1){
				l = h;
			}
			else{
				r = h;
			}
		}
		b = l;

		l = j;
		r = N + 1;
		while(r - l > 1){
			h = (l + r) / 2;
			if(t.query(j + 1, h + 1) >= 1){
				r = h;
			}
			else{
				l = h;
			}
		}
		c = r;
//		printf("(a, b, c) = (%lld, %lld, %lld)\n", a, b, c);

		ans += i * (b - a) * (c - j);


		l = 0;
		r = j;
		while(r - l > 1){
			h = (l + r) / 2;
			if(t.query(h, j) >= 1){
				l = h;
			}
			else{
				r = h;
			}
		}
		a = l;

		l = j;
		r = N + 1;
		while(r - l > 1){
			h = (l + r) / 2;
			if(t.query(j + 1, h + 1) >= 1){
				r = h;
			}
			else{
				l = h;
			}
		}
		b = r;

		l = j;
		r = N + 1;
		while(r - l > 1){
			h = (l + r) / 2;
			if(t.query(j + 1, h + 1) >= 2){
				r = h;
			}
			else{
				l = h;
			}
		}
		c = r;
//		printf("(a, b, c) = (%lld, %lld, %lld)\n", a, b, c);

		ans += i * (j - a) * (c - b);


		t.update(j, 1);
//		printf("ans = %lld\n", ans);
	}
	printf("%lld\n", ans);
	return 0;
}