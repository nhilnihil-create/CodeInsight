#include <iostream>
#include<iomanip>

using namespace std;

const double PI = 3.141592653589;

int main(int argc, char **argv)
{
	double x;
    cin>>x;
    cout.setf(ios::fixed);
    cout<<setprecision(6)<<PI*x*x;
    cout<<' ';
    cout<<setprecision(6)<<2*PI*x;
    
    //cin>>x;
	return 0;
}