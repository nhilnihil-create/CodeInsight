#include <iostream>

int main()
{
    using namespace std;
    
    int a;
    long long int b, n;
    cin >> a >> b >> n;
    cout << min(b - 1, n) * a / b - a * (min(b - 1, n) / b) << endl;
    return 0;
}
