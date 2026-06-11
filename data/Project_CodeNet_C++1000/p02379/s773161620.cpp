#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]){
	long double x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	long double distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	cout << fixed << std::setprecision(8) << distance << endl;
	return 0;
}