#include<iostream>
using namespace std;
long long int a,b,c,d;
long long int max(long long int x,long long int y){
	if(x>y)return x;
	return y;
}
int main(){
	cin>>a>>b>>c>>d;
	cout<<max(a*c,max(a*d,max(b*c,b*d)))<<endl;
	return 0;
}