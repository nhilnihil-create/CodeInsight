#include<bits/stdc++.h>
using namespace std;

#define DIV 1000000007
#define BLACK 0
#define WHITE 1

long long N;
long long ban[100005];
string S;

int main(){
	cin >> N;
	cin >> S;

	long long left = 0;
	long long ans = 1;
	for(long long i = 0; i < 2*N; i++){
		if(i%2 == 0){
			if(S[i] == 'B'){
				left++;
			}else{
				ans *= left;
				ans %= DIV;
				left--;
			}
		}else{
			if(S[i] == 'B'){
				ans *= left;
				ans %= DIV;
				left--;
			}else{
				left++;
			}
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
