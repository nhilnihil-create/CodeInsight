#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    long long K; cin >> K;

    long long a = 7 % K, ans = 1;
    for(int i=0; i<K; ++i)
    {
        if(a == 0)
        {
            cout << ans << endl;
            return 0;
        }
        a = (10*a + 7) % K;
        ++ans;
    }
    cout << -1 << endl;
    return 0;
}