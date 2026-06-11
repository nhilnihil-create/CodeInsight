#include <iostream>
#include <cstdlib>
#include <vector>
//shellSort(A, n) は、一定の間隔 g だけ離れた要素のみを対象とした挿入ソートである insertionSort(A, n, g) を、最初は大きい値から g を狭めながら繰り返します。これをシェルソートと言います。
//上の疑似コードの ? を埋めてこのプログラムを完成させてください。n と数列 A が与えられるので、疑似コード中の m、m 個の整数 Gi(i=0,1,...,m－1)、入力 Aを昇順にした列を出力するプログラムを作成してください。ただし、出力は以下の条件を満 たす必要があります。


using namespace std;
int cnt = 0;
vector<int> G;
int c = 0;
void insertionSort(int A[], int n, int g){
	for(int i = g; i < n; i++){
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v){
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}
void shellSort(int A[], int n){
	int h = 1;
	do{
		G.push_back(h);
		h = 3 * h + 1;
		c++;
	}while(h < n);
	for(int i = c - 1; i >= 0; i--) insertionSort(A, n, G[i]); 
}
int main(){
	int n;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; i++) cin >> A[i];
	shellSort(A, n);
	cout << c << '\n';
	
	for(int i = c - 1; i >= 0; i--){
		cout << G[i]; 
		if(i != n - 1) cout << ' ';
	}
	cout << '\n';
	cout << cnt << '\n';
	for(int i = 0; i < n; i++) cout << A[i] << endl;
}


