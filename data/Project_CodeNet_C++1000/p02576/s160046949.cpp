#include<bits/stdc++.h>
using namespace std;
int main() {
	int X,N,T;
	cin>>N>>X>>T;
	int C = ((N+X-1)/X)*T;
	cout<<C<<endl;
}