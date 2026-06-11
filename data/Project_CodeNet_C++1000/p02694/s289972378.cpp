#include <iostream>
#include<map>
using namespace std;

int main()
{
    long long N;
    cin >> N;

    long long now=100,ans = 0;

    while (now < N)
    {
        now += now / 100;
        ans++;
    }

    cout << ans << endl;
}