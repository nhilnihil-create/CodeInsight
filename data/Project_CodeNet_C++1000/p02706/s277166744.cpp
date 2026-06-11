#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int Ai;
        cin >> Ai;
        N -= Ai;
        if (N < 0)
            break;
    }
    cout << (N<0 ? -1 : N) << endl;
    return 0;
}