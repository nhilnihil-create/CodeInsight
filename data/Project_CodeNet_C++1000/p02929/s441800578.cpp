#include<bits/stdc++.h>
using namespace std;

#define DIV 1000000007
#define BLACK 0
#define WHITE 1

long long N;
long long ban[200005];
string S;

int main(){
	cin >> N;
	cin >> S;

	for(long long i = 0; i < 2*N; i++){
		if(i%2 == 0){
			if(S[i] == 'B'){
				ban[i] =  WHITE;
			}else{
				ban[i] =  BLACK;
			}
		}else{
			if(S[i] == 'B'){
				ban[i] =  BLACK;
			}else{
				ban[i] =  WHITE;
			}
		}
	}
	

	long long left = 0;
	long long ans = 1;

	for(long long i = 0; i < 2*N; i++){
		if(ban[i] == WHITE){
			left++;
		} else {
			ans *= left;
			ans %= DIV;
			left--;
		}
	}

	if(left!=0){
		cout << 0 << endl;
		return 0;
	}

	for(long long i = 1; i <= N; i++){
		ans *= (i);
		ans %= DIV;
	}
	cout << ans << endl;
}
