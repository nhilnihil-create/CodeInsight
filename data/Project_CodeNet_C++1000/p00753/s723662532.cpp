//チェビシェフの定理
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int loader;//ローダー
	bool isprime = false;//素数判定用
	int primecount = 0;//素数の数

	while (1){
		cin >> loader;
		if (loader == 0)break;

		//素数チェック
		if (loader <= 2){//1,2なら1個(2 or 3)のみ
			cout << 1 << endl;
			continue;
		}

		//それ以外
		primecount = 0;
		for (int i = loader + 1; i <= loader * 2; ++i){
			isprime = true;
			if (i % 2 == 0){
				isprime = false;
			} else{
				for (int j = 3; j <= sqrt(i); j += 2){
					if (i % j == 0){
						isprime = false;
						break;
					}
				}
			}
			if (isprime)++primecount;
		}
		cout << primecount << endl;
	}
	return 0;
}