#include <bits/stdc++.h>
using namespace std;

int main(){
//int N,A,B,C,D,X,T;
int A=0, i=0;
char s[200000];
cin >> s;
while(s[i]!=NULL){
	A += s[i] -'0';
	i++;
}
if(A%9==0) cout << "Yes" << endl;
else cout << "No" << endl;
}