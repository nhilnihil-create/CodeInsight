#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int info[2];
	int math[2];
	int science[2];
	int english[2];
	int S,T;
	cin>>info[0]>>math[0]>>science[0]>>english[0];
	cin>>info[1]>>math[1]>>science[1]>>english[1];
	S=info[0]+math[0]+science[0]+english[0];
	T=info[1]+math[1]+science[1]+english[1];
	if(S<T)cout<<T<<endl;
	else cout<<S<<endl;
	return 0;
}