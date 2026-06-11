#include <iostream>
#include<deque>
using namespace std;

int main()
{

    deque<long long> D{1, 2, 3, 4, 5, 6, 7, 8, 9};

    int N;
    cin>>N;
    for (int i = 1; i < N; i++)
    {
        long long tmp = D.front();
        D.pop_front();
        if (tmp % 10 != 0)
        {
            D.push_back(10 * tmp + tmp % 10 - 1);
        }
        D.push_back(10 * tmp + tmp % 10);
        if (tmp % 10 != 9)
        {
            D.push_back(10 * tmp + tmp % 10 + 1);
        }
    }
    cout << D.front() << endl;
}