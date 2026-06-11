#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <cstdint>
#include <istream>
#include <sstream>
#include <cctype>
#include <functional>
#include <iomanip>
#define rep(i,N) for(ll i=0;i<N;i++)
#define disp(a) cout << a << endl;
#define PI 3.1415926535897932384626433
//cout << fixed << setprecision(20) << ** << endl;
typedef long long ll;
using namespace std;

double deg2rad(double degree)
{
    return degree * PI / 180.0000000000;
}
int main()
{
	ll X,Y,ANS=0;
	cin>>X>>Y;
	if(X==1)ANS=ANS+300000;
	if(Y==1)ANS=ANS+300000;
	if(X==2)ANS=ANS+200000;
	if(Y==2)ANS=ANS+200000;
	if(X==3)ANS=ANS+100000;
	if(Y==3)ANS=ANS+100000;
	if(X==1&&Y==1)ANS=ANS+400000;
	cout<<ANS<<endl;
}