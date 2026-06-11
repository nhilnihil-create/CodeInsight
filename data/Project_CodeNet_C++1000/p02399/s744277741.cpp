//ITP1_4_A
#include<iostream>
using namespace std;

int main()
{
	int a,b;
	
	cin>>a>>b;
	
	cout<<a/b<<" "<<a%b<<" ";
	cout.setf(ios::fixed,ios::floatfield);
	cout<<(double)a/b<<endl;
	
	return 0;
}