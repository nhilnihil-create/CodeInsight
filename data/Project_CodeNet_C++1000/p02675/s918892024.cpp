#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string ans[10] = {"pon", "pon", "hon", "bon", "hon", "hon", "pon", "hon", "pon", "hon"};
    int    n;
    cin >> n;
    cout << ans[(n % 10)] << endl;
    return 0;
}
