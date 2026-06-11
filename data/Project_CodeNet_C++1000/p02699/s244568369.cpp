#include <iostream>
using namespace std;

int main() {
    int s, w;
    cin >> s >> w;

    string answer = (s > w) ? "safe" : "unsafe";
    cout << answer;
}