#include"iostream"
#include"fstream"

using namespace std;

int main(){

	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	int m,n; 							//inputする変数
	int a[6],b[6];						//inputする配列(一桁ずつ)
	int c[21] = { 0 };					//a[]からb[]を引いた結果
	int log = 10, tmp, i, j, k = 0;		//制御用
	bool finish = false;				//breakフラグ

	while (true){
		cin >> m >> n;
//		cout << "fin >>" << m << " " << n << endl<<endl;
		if (n == 0 && m == 0)break;		//最後まで来たらbreak

		for (i = 0; i < 6; i++)a[i] = b[i] = 0;
		for (i = 0; i < 20; i++)c[i]= 0;
		log = 10;
		k = 0;

		for (i = 0; i < n; i++){//a[]に値を代入
			a[i] = m%log / (log/10);
			b[i] = a[i];
			log *= 10;
		}

		while (true){

			if (m == 0 && n == 1){
			//	fout << 0 << " " << 0 << " " << 1 << endl;
				cout << 0 << " " << 0 << " " << 1 << endl;
				finish = true;
			}

			for (i = n; i > 0; i--){//a[]を最大に(bubble sort)
				for (j = 0; j < i - 1; j++){
					if (a[j] < a[j + 1]){
						tmp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = tmp;
					}
				}
			}
			for (i = 6; i > 0; i--){//b[]を最小に(bubble sort)
				for (j = 0; j < i - 1; j++){
					if (b[j] > b[j + 1]){
						tmp = b[j];
						b[j] = b[j + 1];
						b[j + 1] = tmp;
					}
				}
			}
			log = 1;//初期化
			for (i = n; i > 0; i--){
				c[k] += a[i - 1] * log;
				log *=10;
			}
//			cout << "a[ ] : " << c[k] << endl;

			c[k] -= b[0] * 100000 + b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5];

//			cout << "b[ ] : " << b[0] * 100000 + b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5] << endl;

//			cout << "c["<<k<<"] : " << c[k] << endl;

			if (c[k] == m){
			//	fout << 0 << " " << c[k] << " " << k+1 << endl;
				cout << 0 << " " << c[k] << " " << k+1 << endl;
				finish = true;
			}
			if (finish == false){
				for (i = 0; i < k; i++){
					if (c[k] == c[i]){
			//			fout << i+1 << " " << c[k] << " " << k - i << endl;
						cout << i+1 << " " << c[k] << " " << k - i << endl;
						finish = true;
					}
				}
			}
//			cout << "閑話休題" << endl;

			for (i = 0; i < 6; i++)a[i] = b[i] = 0;//初期化
			log = 10;//初期化

			for (i = 0; i < n; i++){//a[]に値を代入
				a[i] = c[k]%log / (log / 10);
				b[i] = a[i];
				log *= 10;
			}
			k++;
			if (k > 20 || finish == true){
				finish = false;
				break;
			}
		}
	}
	return 0;
}