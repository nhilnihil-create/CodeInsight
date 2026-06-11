#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N;
string S;
int z_algorithm[5005];


int main(){

	scanf("%d",&N);

	cin >> S;

	int ans = 0;

	for(int i = 0; i < N-1; i++){

		int P_length = N-i;
		z_algorithm[0] = P_length;
		int index = 1,diff = 0,diff_2;

		while(index < P_length){
			while(index+diff < P_length && S[i+index+diff] == S[i+diff])diff++; //不一致箇所はP[diff]とP[index+diff]
			z_algorithm[index] = diff;

			if(diff == 0){ //1文字も一致しない場合
				index++;
				continue;
			}else{ //先頭からdiff文字一致したという事実を利用する

				diff_2 = 1;

				//一致長が[比較の先頭をずらした分だけ]減っていく間、以前の計算結果を再利用する
				while(index+diff_2 < P_length && z_algorithm[diff_2] < diff-diff_2){

					z_algorithm[index+diff_2] = z_algorithm[diff_2];
					diff_2++;
				}

				index += diff_2;
				diff -= diff_2;
			}
		}

		for(int k = 0; k < P_length-1; k++){
			if(z_algorithm[k] > 0 && z_algorithm[k] <= k){

				ans = max(ans,z_algorithm[k]);
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}


