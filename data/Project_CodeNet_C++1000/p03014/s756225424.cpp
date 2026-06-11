#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 2005

int H,W;
int U[SIZE][SIZE],D[SIZE][SIZE],L[SIZE][SIZE],R[SIZE][SIZE];
char buf[SIZE][SIZE];


int main(){

	scanf("%d %d",&H,&W);

	for(int row = 0; row < H; row++){

		scanf("%s",buf[row]);
	}

	//Uを計算
	for(int col = 0; col < W; col++){

		if(buf[0][col] == '.'){

			U[0][col] = 0;
		}
	}
	for(int row = 1; row < H; row++){
		for(int col = 0; col < W; col++){
			if(buf[row][col] != '.')continue;

			if(buf[row-1][col] == '.'){

				U[row][col] = U[row-1][col]+1;

			}else{

				U[row][col] = 0;
			}
		}
	}

	//Dを計算
	for(int col = 0; col < W; col++){

		if(buf[H-1][col] == '.'){

			D[H-1][col] = 0;
		}
	}
	for(int row = H-2; row >= 0; row--){
		for(int col = 0; col < W; col++){
			if(buf[row][col] != '.')continue;

			if(buf[row+1][col] == '.'){

				D[row][col] = D[row+1][col]+1;

			}else{

				D[row][col] = 0;
			}
		}
	}

	//Lを計算
	for(int row = 0; row < H; row++){

		if(buf[row][0] == '.'){

			L[row][0] = 0;
		}
	}
	for(int col = 1; col < W; col++){
		for(int row = 0; row < H; row++){
			if(buf[row][col] != '.')continue;

			if(buf[row][col-1] == '.'){

				L[row][col] = L[row][col-1]+1;

			}else{

				L[row][col] = 0;
			}
		}
	}

	//Rを計算
	for(int row = 0; row < H; row++){

		if(buf[row][W-1] == '.'){

			R[row][W-1] = 0;
		}
	}

	for(int col = W-2; col >= 0; col--){
		for(int row = 0; row < H; row++){
			if(buf[row][col] != '.')continue;

			if(buf[row][col+1] == '.'){

				R[row][col] = R[row][col+1]+1;

			}else{

				R[row][col] = 0;
			}
		}
	}

	int ans = 0;

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){
			if(buf[row][col] != '.')continue;

			ans = max(ans,U[row][col]+D[row][col]+L[row][col]+R[row][col]+1);
		}
	}

	printf("%d\n",ans);

	return 0;
}
