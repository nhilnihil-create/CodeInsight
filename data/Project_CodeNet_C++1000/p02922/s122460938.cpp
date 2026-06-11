#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int A, B;
    cin >> A >> B;
    int x = 1;
    int i = 0;
    while(x < B){
        x = x - 1 + A;
        i++ ;
    }
    printf("%d\n", i);

}