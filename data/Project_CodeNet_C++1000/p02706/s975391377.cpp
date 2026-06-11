#include <bits/stdc++.h>
using namespace std;

int main(){
int N,M;
int A,C=0;
cin >> N>>M;
for(int i=0;i<M;i++){
	cin >> A; 
	C += A;
}

if(C<=N)cout << N-C << endl;
else cout << -1 << endl;
}