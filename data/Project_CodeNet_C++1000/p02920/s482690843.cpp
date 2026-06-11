#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 262144

int N;
int POW[20];
int table[SIZE];

int main(){

	POW[0] = 1;
	for(int i = 1; i < 20; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%d",&N);

	for(int i = 0; i < POW[N]; i++){

		scanf("%d",&table[i]);
	}

	sort(table,table+POW[N]);

	vector<int> S;
	S.push_back(table[POW[N]-1]);

	table[POW[N]-1] = -1;

	for(int i = 0; i < N; i++){

		vector<int> work = S;
		sort(work.begin(),work.end());

		for(int k = POW[N]-1; k >= 0; k--){
			if(table[k] == -1)continue;

			if(work.back() <= table[k])continue;

			work.pop_back();
			S.push_back(table[k]);
			table[k] = -1;

			if(work.size() == 0)break;
		}

		if(work.size() > 0){

			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");

	return 0;
}
