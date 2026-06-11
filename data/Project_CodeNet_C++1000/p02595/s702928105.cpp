#include <iostream>
#include <math.h>
using namespace std;

long long pow2[1000000];
int counter , x , y;

double Distance(int x , int y){
   double Dis = sqrt(pow2[abs(x)] + pow2[abs(y)] ) ;
   return Dis;
}

int main()
{
	for(int i = 0 ; i < 1000000 ; ++i)
		pow2[i] = pow(i , 2);
	
	int t = 0;
	cin>>t;
	double d = 0;
	cin>>d;
	
	while(t--){
		cin>>x>>y;
		if (Distance(x , y) <= d)
		   counter++;
	}
	
	cout << counter << endl;
	return 0;
}