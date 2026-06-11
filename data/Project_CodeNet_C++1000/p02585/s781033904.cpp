#include "bits/stdc++.h"
using namespace std;

long long P[5010];
long long C[5010];

int main() {
	long long N, K;
	cin >> N >> K;
	for (long long i = 1; i <= N; i++) {
		cin >> P[i];
	}
	for (long long i = 1; i <= N; i++) {
		cin >> C[i];
	}

	long long nmax = -1000000000;//各Nについてのmax
	long long ntemp = 0;//各Nについての途中得点
	long long allmax = -1000000000;//全部の最大値
	int flag;
	int cnt;

	//全マスについて最大値を計算する
	for (int i = 1; i <= N; i++) {
		nmax = -1000000000;
		ntemp = 0;
		flag = 1;//サイクルを回ったかどうかのフラグ
		cnt = 1;//サイクルの数 最初の１回は動いてからスタート
		int temp = i;//最初のマスを記録
		int now = temp;//現在のマス
		//最初の移動をする
		now = P[now];
		ntemp += C[now];
		nmax = max(nmax, ntemp);
		//スタート
		do {
			if (cnt == K) {
				flag = 0;//サイクルを回らずに終わった場合
				//cout<<"サイクルを回らずに終わった場合"<<endl;
				break;
			}
			now = P[now];
			ntemp += C[now];
			nmax = max(nmax, ntemp);
			cnt++;

		} while (now != temp);
		//cout<<now<<" "<<cnt<<"flag"<<nmax<<"ntemp"<<ntemp<<endl;

		//サイクルを回らずに終わった場合
		if (flag != 1) {
			allmax = max(allmax, nmax);
			continue;
		}

		//サイクルした場合
		  //サイクル後スコアが減少している場合
		if (ntemp <= 0) {
			allmax = max(allmax, nmax);
			//cout<<nmax<<"$"<<allmax<<endl;
			continue;
		}

		//サイクル後スコアが増加している場合
		if (ntemp > 0) {
			long long sc = K / cnt;//何サイクル回ったか
			//サイクルを回った余りの数　zc
			long long zc = K - (sc - 1) *cnt;//残り回数を計算 1周余計に回す
			ntemp = (sc - 1)*ntemp;
			nmax = max(nmax, ntemp);
			//cout<<"sc"<<sc<<"zc"<<zc<<"ntemp"<<ntemp<<endl;
			for (int j = 0; j < zc; j++) {
				now = P[now];
				ntemp += C[now];
				//cout<<i<<"###"<<ntemp<<endl;
				nmax = max(nmax, ntemp);
			}
			//cout<<nmax<<"*"<<allmax<<endl;
			allmax = max(allmax, nmax);
			continue;
		}
	}
	//cout<<flag<<" "<<cnt<<endl;
	cout << allmax << endl;
	return 0;
}
