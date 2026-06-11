#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


char buf[105];

int main(){

	scanf("%s",buf);

	bool FLG = true;

	for(int i = 0; buf[i] != '\0'; i++){
		if(i%2 == 0){

			if(buf[i] != 'R' && buf[i] != 'U' && buf[i] != 'D'){

				FLG = false;
				break;
			}

		}else{

			if(buf[i] != 'L' && buf[i] != 'U' && buf[i] != 'D'){

				FLG = false;
				break;
			}
		}
	}

	if(FLG){

		printf("Yes\n");

	}else{

		printf("No\n");
	}

	return 0;
}
