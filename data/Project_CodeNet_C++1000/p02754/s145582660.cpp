#include <iostream>

using namespace std;

int main()
{
    long long N, A, B;
    long long groupCount, rest;
    long long numA = 0;

    cin >> N >> A >> B;

    groupCount = N / (A + B);
    rest = N % (A + B);

    numA = groupCount * A;
    numA += min(A, rest);

    cout << numA << endl;

    return 0;
}