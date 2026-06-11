// Problem - Y (indu)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A{0};
    long long B{0},N{0};
    double value1{0},value2{0};

    scanf("%d %lli %lli",&A,&B,&N);

    //N--;

    if(N < B){
        value1 =floor( A * N / B );
        value2 =floor( N / B );
        value2 *= A;
        printf("%.0lf\n",value1 - value2);
    }else{
        if(N % B != B - 1){
            N -= (N % B) + 1; 
        }
        value1 =floor( A * N / B );
        value2 =floor( N / B );
        value2 *= A;
        printf("%.0lf\n",value1 - value2);
    }

    return 0;
}