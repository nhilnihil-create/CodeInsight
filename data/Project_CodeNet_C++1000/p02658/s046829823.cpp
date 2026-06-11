#include <iostream>
using namespace std;

long long MAX = 1e18;
int main(void)
{
    int n; cin >> n;
    long long prod = 1;
    long long a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (prod  != 0)
        {
            if (a <= MAX / prod || a == 0) prod *= a;
            else prod = -1;
        }
    }
    cout << prod << endl;
}