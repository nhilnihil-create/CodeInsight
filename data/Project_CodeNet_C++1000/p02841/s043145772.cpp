//sumitrust2019
//Chandigarh University
//author: shivamkr21 (pseduo coders)
#include<bits/stdc++.h>
//#include "boost/multiprecision/cpp_int.hpp"
//#define eint int1024_t
#define lli long long int
#define endl "\n"
#define vint vector<int>
#define vvint vector< vector<int> >
#define pub push_back 
#define mod 1000000007
//using namespace boost::multiprecision;
using namespace std;
lli fun_cal(lli x, lli y, lli l, lli r);
int main()
{
    std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lli m1,d1,m2,d2,res=0;
	cin>>m1>>d1>>m2>>d2;
	if(m1==1 && d1==31)
		res=1;
	else if(m1==2 && d1==28)
	{
		if(m2==3 && d2==1)
			res=1;
	}
	else if(m1==2 && d1==29)
		res=1;
	else if(m1==3 && d1==31)
		res=1;
	else if(m1==4 && d1==30)
		res=1;
	else if(m1==5 && d1==31)
		res=1;
	else if(m1==6 && d1==30)
		res=1;
	else if(m1==7 && d1==31)
		res=1;
	else if(m1==8 && d1==31)
		res=1;
	else if(m1==9 && d1==30)
		res=1;
	else if(m1==10 && d1==31)
		res=1;
	else if(m1==11 && d1==30)
		res=1;
	else if(m1==12 && d1==31)
		res=1;

	cout<<res;

	return 0;

}