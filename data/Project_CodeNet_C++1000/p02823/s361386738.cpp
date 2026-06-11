#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long N, A, B;
    cin >> N >> A >> B;

    long long ans;
    if ((B - A) % 2 == 0)
    {
        ans = (B - A) / 2;
    }else
    {
        long long dA, dB;
        dA = A - 1;
        dB = N - B;
        if (dA < dB)
        {
            ans = dA + 1 + (B - A - 1) / 2;
        }else
        {
            ans = dB + 1 + (B - A - 1) / 2;
        }
        
    }
    
    cout << ans << endl;

    return 0;
}