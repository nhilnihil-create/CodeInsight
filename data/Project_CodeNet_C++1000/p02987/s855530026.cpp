#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int table[26];
char S[5];

int main(){

	for(int i = 0; i < 26; i++){

		table[i] = 0;
	}

	scanf("%s",S);

	for(int i = 0; S[i] != '\0'; i++){

		table[S[i]-'A']++;
	}

	int num_2 = 0;

	for(int i = 0; i < 26; i++){
		if(table[i] == 2){

			num_2++;
		}
	}

	if(num_2 == 2){

		printf("Yes\n");

	}else{

		printf("No\n");
	}

	return 0;
}
