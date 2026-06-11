#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{	


	int h1,m1,h2,m2,K;
	cin>>h1>>m1>>h2>>m2>>K;
	if(m1>m2){h2--;m2+=60;}
	
	cout<< (h2-h1)*60+(m2-m1)-K<<endl;
	return 0;
}