#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	int size, count = 0, count1 = 0, count2 = 0;
	cin >> size;
	vector<int> v(size);		//順番に入れ替えてチェックする用の順列
	vector<int> first(size);	//1個目の順列
	vector<int> second(size);	//2個目の順列

	//チェックする順列の入力を受け取る
	rep(i, size) { cin >> first[i]; }
	rep(i, size) { cin >> second[i]; }
	
	//チェック用順列の初期化
	rep(i, size)
	{
		v[i] = i+1;
	}

	//順列が存在する限り繰り返す
	do {
		count++;	//何個目の順列をチェックしているか記録

		rep(i, size)
		{
			//順列が一致したとき、辞書順で何番目だったかか記録
			if (count1 == 0 && v == first ) count1 = count;
			if (count2 == 0 && v == second) count2 = count;

			//チェックの途中であっても二つとも一致したらループを抜ける
			if (count1 != 0 && count2 == 0) break;
		}
	} while (std::next_permutation(v.begin(), v.end()));

	cout << abs(count1 - count2) << endl;
}