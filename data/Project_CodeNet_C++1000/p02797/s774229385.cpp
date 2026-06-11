#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K, S;
    cin >> N >> K >> S;

    int cnta = K;
    int cntb = N - K;
    while (cnta > 0)
    {
        cout << S << ' ';
        cnta--;
    }
    while (cntb > 0)
    {
        if (S < 1000000000)
        {
            cout << S + 1 << ' ';
        }else
        {
            cout << S - 1 << ' ';
        }
        cntb--;
    }
    
    cout << endl;

    return 0;
}