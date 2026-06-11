#include <bits/stdc++.h>
using namespace std;

#define unit 0
int N; // 葉の数
vector<int> value; // セグ木,サイズは後。
using ll =long long;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
//Write From this Line
// セグ木操作用の関数の定義
void update(int i, int x) { // 葉の i 番目をxに変更
	i += N - 1;
	value[i] = x;
	while (i > 0){
		i = (i - 1) / 2 ;
		value[i] = max(value[i * 2 + 1], value[i * 2 + 2]);
	}
}
int query(int a, int b, int k, int l, int r) { // [a,b)を聞かれている時,kに聞く。k は[l,r)を担当する(rは担当しない
	if(r <= a || b <= l) return unit; // 区間が全くかぶらない
	if(a <= l && r <= b) return value[k]; // 区間が完全にかぶっている。
	else {
		int c1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int c2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(c1, c2);
	}
}

int main()
{
	int n;
	cin >> n;
	N = 1;
	while(N < n) N *= 2;
	value = vector<int> (2 * N - 1, unit);
	rep(i,n){
		int x;
		cin >> x;
		update(i,x);
	}
	rep(i,n){
		cout << max(query(0,i, 0, 0, N), query(i+1,N,0,0,N)) << endl;
	}
}
