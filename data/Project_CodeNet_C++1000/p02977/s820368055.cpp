//N = 4, 5, 6, 12を手で構築すれば大体分かる。
//N = 4を考えると気付くこと：Nが2の累乗だとNとNの間のxorはN未満になるので不可能。
//N = 5をスムーズに構築するには、「100と100の間に101を挟む」「100, 101を3以下の数の間に挟まない場合を考える」
//をするとよく、N = 3のパスを上手く使うことができる。結局、2n xor (2n + 1) = 1が割と大事な性質だったりする。
//N = 6ができれば大体何でもできそうで、できなければNが偶数のときできなさそうだな～と当てをつける。
//(2n + 1) xor (2n + 2)が2^hoge - 1の形になって、これは2n + 2側が2でhoge - 1回割り切れるとかうんたらかんたら。
//つまり、Nを2で何回割り切れるかが大事そうで、するとN = 6, 10, 14…あたりは本質的に同じと見た。
//となると、N = 12あたりで試すのが良さそうで、これはN = 11を構築してから、12 xor 11 = 2^3 - 1を利用してよしなにやるとできる。
#include <iostream>
using namespace std;

int n;
int a[200000], b[200000];
int cor = 0;

void add_edge(int u, int v) {
	a[cor] = u;
	b[cor] = v;
	cor++;
}

void print() {
	int i;
	cout << "Yes" << endl;
	for (i = 0; i < 2 * n - 1; i++) {
		cout << a[i] << " " << b[i] << endl;
	}
}

int main() {
	int i;
	
	cin >> n;
	for (i = 0; (1 << i) <= n; i++) {
		if ((1 << i) == n) {
			cout << "No" << endl;
			return 0;
		}
	}
	
	for (i = 5; i <= n; i += 2) {
		add_edge(i - 1, i);
		add_edge(i, 1);
	}
	
	add_edge(1, 2);
	add_edge(2, 3);
	add_edge(3, n + 1);
	
	for (i = 3; i <= n; i += 2) {
		add_edge(n + 1, n + i - 1);
		add_edge(n + i - 1, n + i);
	}
	
	if (n % 2 == 0) {
		add_edge(n, n - 1);
		int x = n ^ (n - 1);
		add_edge(n + x - 1, 2 * n);
	}
	
	print();
	return 0;
}
