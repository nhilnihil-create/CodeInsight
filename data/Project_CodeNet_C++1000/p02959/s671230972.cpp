#include<bits/stdc++.h>

#define ull unsigned long long

using namespace std;

main(void)
{
    

    ull n; 
    cin >> n;
    ull *A = new ull[n];
    ull *B = new ull[n+1];

    for (ull i = 0; i <= n; ++i)
        cin >> B[i];
    for (ull i = 0; i < n; ++i)
        cin >> A[i];
   
    ull P = 0;
    for (ull i = 0; i < n; ++i)
    {
        if(A[i] <= B[i])
        {
            P += A[i];
            B[i] -= A[i];
            A[i] = 0;
        }
        else if(A[i] > B[i])
        {
            P += B[i];
            A[i] -= B[i];
            B[i] = 0;
            if (A[i] >= B[i+1])
            {
                P += B[i+1]; 
                B[i+1] = 0; 
            }
            else if (A[i] < B[i+1])
            {
                P += A[i]; 
                B[i+1] -= A[i]; 
                A[i] = 0;
            }
        }
    }
    //for (ull i = 0; i < n; ++i)
    //    cout << A[i] << " ";
    //cout << "\n";
    //for (ull i = 0; i <= n; ++i)
    //    cout << B[i] << " ";
    cout << P;

    return 0;
}