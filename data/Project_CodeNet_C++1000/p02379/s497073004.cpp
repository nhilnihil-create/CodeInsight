#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	long double x1,y1;
    long double x2,y2;
    
    cin>>x1>>y1>>x2>>y2;
    long double result;
    result = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    cout.setf(ios::fixed);
    cout<<setprecision(8)<<result<<endl;
    
    
	return 0;
}