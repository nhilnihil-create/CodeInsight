#include <iostream>
#include <algorithm>

#define MAXNUM 1000001
#define MAX 100
using namespace std;

int all[MAXNUM], odd[MAXNUM], fourall[MAXNUM], fourodd[MAXNUM];

int main()
{
	int n;
	int counter = 0;

	//配列の初期化
	for (int i = 1; i < MAXNUM; i++){
		all[i] = MAX;
		odd[i] = MAX;

	}

	//1からMAXNUMまでの中に存在する正四面体数を洗い出す．
	long long int now = 0;
	long long int allcounter = 1, oddcounter = 1;
	while (1){
		now++;

		int four = now * (now + 1) * (now + 2) / 6;
		//cout << four << endl;
		if (four > MAXNUM)
			break;
		
		all[four] = 1;
		fourall[allcounter++] = four;

		if (four % 2 == 1){
			odd[four] = 1;
			fourodd[oddcounter++] = four;
		}
	}

	//cout << allcounter << ", " << oddcounter << endl;

	//1からMAXNUMまで，配列を埋める.
	for (int i = 1; i < allcounter; i++){
		const int num_all = fourall[i];

		for (int j = 1; j < (MAXNUM - num_all); j++){
			all[j + num_all] = min(all[j + num_all], 1 + all[j]);
		}
	}

	for (int i = 1; i < oddcounter; i++){
		const int num_odd = fourodd[i];

		for (int j = 1; j < (MAXNUM - num_odd); j++){
			odd[j + num_odd] = min(odd[j + num_odd], 1 + odd[j]);
		}
	}


	/*
	for (int i = 1; i < MAXNUM; i++){
		for (int j = 1; fourall[j] < i; j++){
			all[i] = min(all[i], 1 + all[i - fourall[j]]);
			cout << all[i];
		}
		for (int j = 1; fourodd[j] < i; j++){
			odd[i] = min(odd[i], 1 + odd[i - fourodd[j]]);
		}

	}

	*/

	//cout << "a";
	//入力
	while (cin >> n, n)
		cout << all[n] << " " << odd[n] << endl;

	return 0;

}