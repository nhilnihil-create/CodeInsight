#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    if (n%2 == 0) {
        printf("%.10f\n", 0.5);
    }else{
        printf("%.10f\n", (double)(n/2+1)/n);
    }
    return 0;
}
