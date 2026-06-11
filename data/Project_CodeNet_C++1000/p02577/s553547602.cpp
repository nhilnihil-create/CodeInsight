#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char N[200010];
    scanf("%s", N);
    
    int len = strlen(N);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += (N[i] - '0');
    }
    if (sum % 9 == 0) {
        printf("%s\n", "Yes");
    } else {
        printf("%s\n", "No");
    }
}