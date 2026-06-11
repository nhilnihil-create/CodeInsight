#include<iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>



int main()
{
    int N;
    std::cin >> N;
    std::vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }


    int x = 0;
    for (int i = 0; i < N-1; i+=2)
    {
        x += A[i] - A[i+1];
    }
    x += A[N-1];
    
    printf("%d ", x);

    for (int i = 0; i < N - 1; i++)
    {
        x = 2*A[i] - x;
        if (i != N - 2) 
        {
            printf("%d ", x);
        }
        else
        {
            printf("%d\n", x);
        }
    }

    return 0;
}