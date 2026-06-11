#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int max_num = min(b, c / 2);
    int num_of_divisors;
    for (int i = a; i <= b; ++i)
    {
        if (c % i == 0)
        {
            num_of_divisors++;
        }
    }
    cout << num_of_divisors << endl;
}
