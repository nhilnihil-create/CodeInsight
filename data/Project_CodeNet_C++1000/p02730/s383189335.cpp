#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPalindrome(string s){
    string t(s.rbegin(),s.rend());
    return s == t;
}

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    string left = s.substr(0, (n - 1) / 2);
    string right = s.substr((n + 1) / 2);

    if(isPalindrome(s) && isPalindrome(left) && isPalindrome(right))
        cout << "Yes" << "\n";
    else cout << "No" << "\n";
    
    return 0;
}