#include<iostream>

using namespace std;

int D,T,S;

int main(void)
{
	cin >> D >> T >> S;
	
	double Time = D / (double)S;
	
	if(Time > T) cout <<"No"<<endl;
	else cout << "Yes" << endl;
	
	return 0;
}