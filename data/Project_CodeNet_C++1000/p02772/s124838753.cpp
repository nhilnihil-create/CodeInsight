#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	vector<int> A;

	int denied = 0;
	for(int i=0; i<N; i++){
		int a; cin >> a;
		if((a % 2) == 0){
			if((a % 3) != 0 && (a % 5) != 0){
				denied = 1;
				break;
			}
		}
	}
	if(denied == 1){
		printf("DENIED\n");
	}
	else{
		printf("APPROVED\n");
	}
	return 0;
}