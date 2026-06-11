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

	lli n,res=0;
	cin>>n;

	if(n>=100 && n<=105)
		res=1;
	else if(n>=200 && n<=210)
		res=1;
	else if(n>=300 && n<=315)
		res=1;
	else if(n>=400 && n<=420)
		res=1;
	else if(n>=500 && n<=525)
		res=1;
	else if(n>=600 && n<=630)
		res=1;
	else if(n>=700 && n<=735)
		res=1;
	else if(n>=800 && n<=840)
		res=1;
	else if(n>=900 && n<=945)
		res=1;
	else if(n>=1000 && n<=1050)
		res=1;
	else if(n>=1100 && n<=1155)
		res=1;
	else if(n>=1200 && n<=1260)
		res=1;
	else if(n>=1300 && n<=1365)
		res=1;
	else if(n>=1400 && n<=1470)
		res=1;
	else if(n>=1500 && n<=1575)
		res=1;
	else if(n>=1600 && n<=1680)
		res=1;
	else if(n>=1700 && n<=1785)
		res=1;
	else if(n>=1800 && n<=1890)
		res=1;
	else if(n>=1900 && n<=1995)
		res=1;
	else if(n>=2000 && n<=2100)
		res=1;
	else if(n>2100)
		res=1;

	cout<<res;
	
	
	return 0;

}