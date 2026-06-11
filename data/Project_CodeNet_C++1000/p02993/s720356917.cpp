#include <iostream>
using namespace std;
int main() {
   string S; cin >> S;
   for (int i = 0; i < 3; i++)
   {
        if (S[i] == S[i + 1]) {
            printf("%s\n", "Bad");
            return 0;
        }
   }
    printf("%s\n", "Good");
    return 0;
}