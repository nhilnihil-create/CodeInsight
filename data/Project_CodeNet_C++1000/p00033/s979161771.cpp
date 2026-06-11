#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

stack<int> S1,S2;
int A[10];
bool flag;

int ball(int a){
	while (1){
		flag = false;
		if (S1.top() < A[a]){
			S1.push(A[a]);
			a++; flag = true;
		}
		else if (S2.top() < A[a]){
			S2.push(A[a]);
			a++; flag = true;
		}
		if (flag == false) {
			return 0;
		}
		if (a == 10) {
			return 1;
		}
	}
}



int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int l = 0; l < 10; l++) cin >> A[l];
		S1.push(0);
		S2.push(0);
		int a = 0;
		if (ball(a)) cout << "YES" << endl;
		else cout << "NO" << endl;
		a = 0;
		while (!S1.empty()) S1.pop();
		while (!S2.empty()) S2.pop();
	}
	return 0;
}