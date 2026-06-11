#include<iostream>

using namespace std;

void Cal(int N, int X, int T)
{
    int i = 0;
    for( i = 0; N > 0; i++)
    {
        N -= X;
    }
    cout << i * T;
}
int main()
{
    int X, T, N;
    cin >> N >> X >> T;
    Cal(N, X, T);
    return 0;
}