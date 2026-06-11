#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
using namespace std;
//---------------------------------------
//---------------------------------------

int main(void)
{
	double len_a, len_b, angle_c;
	cout << fixed <<setprecision(4);  //???????°???°????¬¬4????????§??¨?????????(iomanip)
	
	cin >> len_a;
	cin >> len_b;
	cin >> angle_c;
	
	//??¢???S
	cout << len_a * len_b * sin(angle_c * M_PI / 180) * 1 / 2 << endl;
	
	//??¨?????????L
	cout << sqrt(pow(len_a, 2) + pow(len_b, 2)
	             - 2 * len_a * len_b * cos(angle_c * M_PI / 180)) + len_a + len_b
	     << endl;
	
	//??????h
	cout << len_b * sin(angle_c * M_PI / 180) << endl;
	
	
	return 0;
	
}