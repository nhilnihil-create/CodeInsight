#include <iostream>
using namespace std;
int main() {
    string S; cin >> S;
    int N = S.length();
    if (N % 2 != 0) {
        printf("%s\n", "No");
        return 0;
    }
    for (int i = 0; i < N - 1; i += 2)
    {
        if (S[i] == 'h' && S[i + 1] == 'i') {
            printf("%s\n", "Yes");
            return 0;
        }
    }
    printf("%s\n", "No");
    return 0;
}