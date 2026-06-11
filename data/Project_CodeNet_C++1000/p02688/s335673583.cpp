#include <bits/stdc++.h>
using namespace std;

int main(){
int N,B,C=0,K,d;
cin >> N >> K;
vector<int> A(N);

for(int i = 0;i < N; i++){
	A.at(i) = 0;
}

for(int i = 0;i < K; i++){
	cin >> d;
	for(int j = 0;j < d; j++){
		cin >> B;
		A.at(B-1)++;
	}
}
for(int i = 0;i < N; i++){
	if(A.at(i)==0) C++;
}
cout << C << endl;
}