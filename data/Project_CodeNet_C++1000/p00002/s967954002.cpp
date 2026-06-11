#include <iostream>

using namespace std;

int get_digit(int val)
{
    int res = 0;
    while (val > 0) {
	val /= 10;
	res++;
    }
    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b) {
	int sum = a + b;
	cout << get_digit(sum) << endl;
    }
    return 0;
}