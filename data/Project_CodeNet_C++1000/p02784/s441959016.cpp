#include <bits/stdc++.h>
using namespace std;

int main(){
	int H, N;
	cin >> H >> N;
	int A[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
		H -= A[i];
	}
	if(H > 0)cout << "No" << endl;
	else cout << "Yes" << endl;
}
