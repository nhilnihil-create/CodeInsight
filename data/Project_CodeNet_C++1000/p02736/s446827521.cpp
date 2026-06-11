#include<bits/stdc++.h>
using namespace std;

int val[1000003] , N; char str[1000003];

int main(){
	scanf("%d %s" , &N , str + 1); bool flg = 1;
	for(int i = 1 ; i < N ; ++i) flg &= (val[i] = abs(str[i] - str[i + 1])) != 1;
	if(flg) for(int i = 1 ; i < N ; ++i) val[i] >>= 1;
	int sum = 0; for(int i = 1 ; i < N ; ++i) sum ^= (((N - 2) & (i - 1)) == i - 1) & val[i];
	cout << (sum << flg); return 0;
}
