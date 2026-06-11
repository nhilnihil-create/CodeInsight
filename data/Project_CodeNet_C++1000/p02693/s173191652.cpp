#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int k,a,b;
    cin >> k >> a >> b;
    int ans = k;
    for (int i = 0; ans < a; i++)
    {
        ans += k;
    }
    if(b>=ans)
    {
        cout << "OK" << endl;
    }else
    {
        cout << "NG" << endl;
    }

        return 0;
}
