#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.141592653;
const double toRad = PI/180;

int main()
{
	double a,b,c;
    cin>>a>>b>>c;
    cout.setf(ios::fixed);
    //double sinc;
    //sinc = sin(c*toRad);
    //cout<<sinc<<endl;
    //cout<<c<<endl;
    //cout<<sin(c)<<endl;
    //cout<<cos(c)<<endl;
    double S,L,h;
    S = (a*b*sin(c*toRad))/2;
    L = a+b+sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c*toRad));
    h = b*sin(c*toRad);
    
    cout<<setprecision(8)<<S<<endl<<L<<endl<<h<<endl;
    
	return 0;
}