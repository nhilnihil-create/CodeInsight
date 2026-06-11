#include <iostream>
using namespace std;

int main() {
    string n;
    cin >> n;

    string answer = (n.find("7") != std::string::npos) ? "Yes" : "No";
    cout << answer;
}