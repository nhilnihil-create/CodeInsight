#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
#define PI 3.14159265358979323846
using namespace std;
int main()
{
	//int n;
	//cin >> n;
	//if (n % 10 == 3)
	//	cout << "bon";
	//else if (n % 10 == 0 || n % 10 == 1 || n % 10 == 6 || n % 10 == 8)
	//	cout << "pon";
	//else
	//	cout << "hon";

	//int n = 0;
	//cin >> n;
	//string duck;
	//cin.ignore();
	//getline(cin, duck);
	//if (n > duck.size())
	//	n = duck.size();
	//for (int i = 0; i < n; i++) {
	//	cout << duck[i];
	//}
	//if(n<duck.size())
	//cout << "...";

	double h, m;
	int a, b;
	cin >> a >> b;
	cin >> h >> m;
	 
	
	double degree = abs(h * 30+m/60.0*30 - m * 6);
	
	if (degree > 180)
		degree = 360 - degree;
	
	if (degree == 180)
	{
		cout <<fixed<<setprecision(20)<< a + b;
	}
	else 
	{
		double duck = 0;
		double delta = degree*PI / 180.0;
		duck = pow(a, 2) + pow(b, 2) - 2 * a*b*cos(delta);
		cout << fixed << setprecision(20) << pow(duck, 0.5);
	}



    return 0;
}

