#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int N;
vector<int> hist; // カードの分布

/*
	異なる数字からなるk枚の組を、e列作成することを考える。
	Ai を、横kマス 縦eマス に並べたい。
	
	方法
		Aをソートする
		Aを先頭から取り出し、左上から左下に向かって埋めていく。
		同じ数字がe個連続したら、それ以降の同じ数字は捨てる
	
	
	Aとkが与えられたとき、k*eを埋め尽くせるeの最大値 をどうやって求めるか?
	Aのヒストグラム hist[i]
	捨てた数 T = Σmax(0,hist[i]-e)
	N - T >= k*e の場合に埋め尽くすことができる。
	
	N - Σmax(0,hist[i]-e)) >= k*e
	
	0 < e <= N の全てのeに対して kk[e] = (N-Σmax(0,hist[i]-e)))/e を計算しておく。
	各k に対し kk[e] >= k となる最大のeを探す
*/


int main(){
	cin >> N;
	hist.resize(N);
	for ( int i = 0; i < N; i++ ){
		int A;
		cin >> A;
		hist[A-1]++;
	}
	sort( hist.begin(), hist.end(), greater<int>() );
	
	vector<int> kk(N+1);
	{
		int acc = 0;
		int i = 0;
		for ( int e = N; e >= 1; e-- ){
			while ( e < hist[i] && i < N )
				i++;
			acc += i;
			kk[e] = (N-acc)/e;
			
			//cout << " e=" << e << " acc=" << acc << " kk[e]=" << kk[e] << endl;
		}
		kk[0] = INT_MAX;
	}
	
	int e = N;
	for ( int k = 1; k <= N; k++ ){
		while ( kk[e] < k )
			e--;
		cout << e << endl;
	}
	
	return 0;
}

