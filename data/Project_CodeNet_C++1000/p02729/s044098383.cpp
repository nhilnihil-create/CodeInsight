#include <bits/stdc++.h>
using namespace std;

int main(){
int M,N,t=0;
cin >> N>>M;
if(N>1) t += N*(N-1)/2;
if(M>1) t += M*(M-1)/2;
cout << t << endl;
}