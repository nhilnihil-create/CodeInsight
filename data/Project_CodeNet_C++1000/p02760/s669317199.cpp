#include <bits/stdc++.h>
using namespace std;

int main(){
	int A[9];
	int chk[9];
	for(int i=0;i<9;i++){
		cin >> A[i];
		chk[i] = 0;
	}
	int N;
	cin >> N;
	int b[N];
	for(int i=0;i<N;i++){
		cin >> b[i];
		for(int j=0;j<9;j++){
			if(A[j] == b[i]) chk[j]++;
		}
	}
	string ans = "No";
	if(chk[0] > 0 && chk[1] > 0 && chk[2] > 0)ans = "Yes";
	if(chk[3] > 0 && chk[4] > 0 && chk[5] > 0)ans = "Yes";
	if(chk[6] > 0 && chk[7] > 0 && chk[8] > 0)ans = "Yes";
	if(chk[0] > 0 && chk[3] > 0 && chk[6] > 0)ans = "Yes";
	if(chk[1] > 0 && chk[4] > 0 && chk[7] > 0)ans = "Yes";
	if(chk[2] > 0 && chk[5] > 0 && chk[8] > 0)ans = "Yes";
	if(chk[0] > 0 && chk[4] > 0 && chk[8] > 0)ans = "Yes";
	if(chk[2] > 0 && chk[4] > 0 && chk[6] > 0)ans = "Yes";
	cout << ans << endl;
}