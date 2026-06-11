#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


struct Info{
	Info(int arg_a,int arg_b){
		a = arg_a;
		b = arg_b;
	}
	int a,b;
};

int main(){

	int N,M;
	scanf("%d %d",&N,&M);

	vector<Info> info;

	ll tmp = (M+1)/2;

	for(int i = 0; i < tmp; i++){

		info.push_back(Info(tmp-(i+1),tmp+i));
	}

	int tmp2 = M-tmp;
	for(int i = 0; i < tmp2; i++){

		info.push_back(Info(2*tmp+tmp2-(i+1),2*tmp+tmp2+(i+1)));
	}

	for(int i = 0; i < info.size(); i++){

		printf("%d %d\n",info[i].a+1,info[i].b+1);
	}

	return 0;
}
