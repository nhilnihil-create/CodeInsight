#include<bits/stdc++.h>
using namespace std;
int main(){
	int A,B,C,D;
	cin>>A>>B>>C>>D;
	int x=(A+D-1)/D;
	int y=(C+B-1)/B;
	cout<<(x>=y?"Yes":"No")<<'\n';
	return 0;
}