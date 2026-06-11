#include<iostream>
using namespace std;
int main()
{
    long int A, B, K;
    cin >> A >> B;
    if(A > B)
    {
        K = B;
        while(K < A)
        {
            K++;
            if(A - K == K - B)
            {
                cout << K;
                return 0;
            }
        }
    }
    else
    {
        K = A;
        while(K < B)
        {
            K++;
            if(B - K == K - A)
            {
                cout << K;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}