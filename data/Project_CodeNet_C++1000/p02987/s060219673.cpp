#include <iostream>
#include <set>
using namespace std;
int main() {
    string S; cin >> S;
    set<char> C;
    for (int i = 0; i < 4; i++) C.insert(S[i]);
    if (C.size() == 2) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}