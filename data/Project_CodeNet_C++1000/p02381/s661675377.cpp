#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
typedef vector<int> Row;
//---------------------------------------
double keisan(Row row, int n);
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
			Row  row;
			for(int i = 0; i < n; i++){
				int tensu;
				cin >> tensu;
				row.push_back(tensu);
			}
			
			cout << keisan(row, n) << endl;
			//row.clear();
		}
	}
	
	return 0;
	
}

//---------------------------------------
double keisan(Row row, int n)
{
	cout << fixed <<setprecision(4);
	double gokei = 0;
	//??????????±???????
	for(int i = 0; i < n; i++){
		gokei += row[i];
	}
	double m = gokei / n;  //m????????????
	
	double a = 0.0;  //a????¨??????????
	
	for(int i = 0; i < n; i++){
		a += pow(row[i] - m, 2);
	}
	a /= n;
	
	return sqrt(a);
}