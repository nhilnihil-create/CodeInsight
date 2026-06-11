#include <iostream>
using namespace std;


int main () {

int a,b,c;
cin >> a >> b >> c;
bool flag=false;

if(a==b && b!=c ) {
	 flag=true;
}
if(b==c && a!=b)
{
	 flag=true;
}
if(c==a && b!=a)
{
	flag=true;
}

if(flag)
{
	cout << "Yes";
}
else
{
	cout << "No";
}

	return 0;
}









