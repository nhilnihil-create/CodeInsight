#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;


int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    if (a >= b) {
        gcd(b, a%b);
    }
    else {
        gcd(a, b%a);
    }

}

int main()
{
    int N, d = 1;
    int sum = 0;
    cin >> N;
    int* A = (int*)malloc(sizeof(int)*(N + 1));
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int k = 2; k <=floor(sqrt(A[i])); k++) {
            d=gcd(k, A[i]);
            if (d != 1) {
                break;
            }
        }
        if (d == 1) {
            sum++;
        }
        
    }
    cout << sum << "\n";
    free(A);
    return 0;
}