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
	ll M,D,i=1,j=1,ANS=0;
	cin>>M>>D;
	while(1){
		//cout<<i<<"月"<<j<<"日"<<endl;
		if((j/10)>=2&&j%10>=2&&(j/10)*(j%10)==i)ANS++;
		if(j==D&&i==M)break;
		else if(j==D){
			i++;
			j=1;
		}
		else j++;
	}
	cout<<ANS<<endl;
}