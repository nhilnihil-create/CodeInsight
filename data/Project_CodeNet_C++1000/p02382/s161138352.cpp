#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
typedef vector<int> Bector;
//---------------------------------------
double p(Bector x, Bector y, int p); 
double p_infinity(Bector x, Bector y);  //?????§????????§????????¢
//---------------------------------------

int main(void)
{
	cout << fixed <<setprecision(5);
	
	int n;  //n?¬????
	Bector x;
	Bector y;
	
	cin >> n;
	
	//????????????x???????´????????´?
	for(int i = 0; i < n; i++){
		int youso;
		cin >> youso;
		
		x.push_back(youso);
	}
	
	//????????????y???????´????????´?
	for(int i = 0; i < n; i++){
		int youso;
		cin >> youso;
		
		y.push_back(youso);
		
	}
	
	cout << p(x, y, 1) << endl
	     << p(x, y, 2) << endl
	     << p(x, y, 3) << endl
	     << p_infinity(x, y) << endl;
	     
	return 0;
	    
}

//---------------------------------------
double p(Bector x, Bector y, int p)
{
	long long int D = 0;
	
	for(int i = 0; i < x.size(); i++){
		D += abs(pow(x[i] - y[i], p));
	}
	
	return pow(D, 1.0/p);
}
//---------------------------------------
double p_infinity(Bector x, Bector y)  //?????§????????§????????¢
{
	int max = abs(x[0] - y[0]);
	
	for(int i = 1; i < x.size(); i++){
		if( abs(x[i] - y[i]) > max){
			max = abs(x[i] - y[i]);
		}
	}
	
	return max;
}