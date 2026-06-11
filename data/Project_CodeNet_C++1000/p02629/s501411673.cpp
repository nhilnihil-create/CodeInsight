#define ll long long int

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
ll arr[N];
bool b[N];

int main() {

    ll n;
    cin >> n;
    string temp = "";
    while (n) {
        char c = ((26 + (n % 26) - 1)) % 26 + 'a';
        temp += c;
        n--;
        n /= 26;
    }

    reverse(temp.begin(), temp.end());
    cout << temp << endl;
    return 0;
}