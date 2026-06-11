#include <bits/stdc++.h>
using namespace std;

int main(){
int N,M,t=0,s=0;
cin >> N >> M;
vector<int> A(N);

for(int i=0; i<N; i++){
	cin >> A.at(i);
	t += A.at(i);
}
for(int i=0; i<N; i++){
	if(4*M*A.at(i) >= t) s++;
}
if(s>=M) cout << "Yes" << endl;
else cout << "No" << endl;
}