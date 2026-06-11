
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s){
    string t = s;
    reverse(t.begin(), t.end());
    // cout << "s: " << s << endl;
    // cout << "t: " << t << endl;
    return t == s;
}

void Main() {
    // input
    string S;
    cin >> S;
    int N = S.size();

    if (!isPalindrome(S)) {
        cout << "No" << endl;
        return;
    }

    int len = (N-1)/2 - 1 + 1;
    if(!isPalindrome(S.substr(1-1, len))) {
        cout << "No" << endl;
        return;
    }

    len = N - (N + 3) / 2 + 1;
    if(!isPalindrome(S.substr((N+3)/2-1, len))) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

    // translate


    // output

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
