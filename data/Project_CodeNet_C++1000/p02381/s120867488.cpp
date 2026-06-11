#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
typedef vector<int> Tensu;
//---------------------------------------
double keisan(Tensu ten);
//---------------------------------------

int main(void)
{
	cout << fixed <<setprecision(4);  //???????°???°????¬¬4????????§??¨?????????(iomanip)
	
	while(true){
		
		int n; //???????????°
		cin >> n;
		
		if(n == 0){
			break;
		}
		else{
			Tensu  ten;
			for(int i = 0; i < n; i++){
				int tensu;
				cin >> tensu;
				ten.push_back(tensu);
			}
			
			cout << keisan(ten) << endl;
			//row.clear();
		}
	}
	
	return 0;
	
}

//---------------------------------------
double keisan(Tensu ten)
{
	double gokei = 0;
	//??????????±???????
	for(int i = 0; i < ten.size(); i++){
		gokei += ten[i];
	}
	double m = gokei / ten.size();  //m????????????
	
	double a = 0;  //a????¨??????????
	
	for(int i = 0; i < ten.size(); i++){
		a += pow(ten[i] - m, 2);
	}
	a /= ten.size();
	
	return sqrt(a);
}