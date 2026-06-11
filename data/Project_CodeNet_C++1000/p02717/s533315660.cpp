#include<iostream>
#include<string>

int Swap(int* a,int* b);

int main()
{
    int A,B,C;
    int X,Y,Z;
    std::cin >> X >> Y >> Z;

    A=X;
    B=Y;
    C=Z;

    Swap(&A,&B);
    Swap(&A,&C);
 
    std::cout << A <<" "<< B <<" "<< C;

    return 0;
}

int Swap(int* a,int* b)
{
    int buf;
    buf = *a;
    *a = *b;
    *b = buf;

    return 0;
}