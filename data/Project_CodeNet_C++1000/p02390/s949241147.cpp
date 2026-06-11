#include <iostream> 
using namespace std;
int main(void)
{
	int s;
	cin >> s;
	int h, m;
	h = s / 3600;
	s = s-h * 3600;
	m = s / 60;
	s = s-m * 60;
	cout << h << ":" << m << ":" << s<<endl;
}
