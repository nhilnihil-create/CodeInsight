#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    cout << ((M*(M-1)) + (N*(N-1)))/2 << endl;
    return 0;
}