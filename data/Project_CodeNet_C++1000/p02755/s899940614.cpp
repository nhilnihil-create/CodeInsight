#include <bits/stdc++.h>
using namespace std;
int main(){
	int A, B;
	cin >> A >> B;
	int ans = -1;
	for(int i = 0;i<B * 20;i++){
		if(i * 8 / 100 == A && i / 10 == B){
			ans = i;
			break; 
		}
	}
	cout << ans << endl;
}
