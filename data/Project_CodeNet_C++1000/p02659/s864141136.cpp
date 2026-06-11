#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll A;
    cin >> A;
    string B_str;
    cin >> B_str;
    ll B100 = 100 * int(B_str[0] - '0') + 10 * int(B_str[2] - '0') + int(B_str[3] - '0');
    cout << A * B100 / 100 << endl;
    return 0;
}
