#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<cstdlib>
#include<typeinfo>
#include<sstream>
#include<list>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define fori(i,k,n) for(int i=k;i<(int)n;i++)
using namespace std;
int stringInt(string a)
{
	return atoi(a.c_str());
}
string intString(int a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}

int main() {
	int n;cin>>n;
	vector<double> X,Y;
	X.push_back(0.0);
	X.push_back(100.0);
	Y.push_back(0.0);
	Y.push_back(0.0);
	double kaku=1.0/3.0*3.14159;
	for(int i=0;i<n;i++)
	{
		int e=X.size();
		vector<double> o,O;
		o.push_back(X[0]);
		O.push_back(Y[0]);
		for(int l=1;l<e;l++)
		{

			double a,b,c;//x
			double A,B,C;//y
			a=(2.0*X[l-1]+1.0*X[l])/3.0;
			c=(1.0*X[l-1]+X[l]*2.0)/3.0;
			A=(2.0*Y[l-1]+1.0*Y[l])/3.0;
			C=(1.0*Y[l-1]+Y[l]*2.0)/3.0;
			b=(c-a)*cos(kaku)-(C-A)*sin(kaku)+a;
			B=(c-a)*sin(kaku)+(C-A)*cos(kaku)+A;

			o.push_back(a);
			o.push_back(b);
			o.push_back(c);
			o.push_back(X[l]);
			O.push_back(A);
			O.push_back(B);
			O.push_back(C);
			O.push_back(Y[l]);
		}
		X=o;Y=O;
	}
	for(int i=0;i<X.size();i++)
	{
		printf("%.8f %.8f\n",X[i],Y[i]);

	}

}