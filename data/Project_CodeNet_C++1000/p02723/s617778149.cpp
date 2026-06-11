#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    SPEED;
    string str;
    cin >> str;
    int flag = 0;
    if (str[2] == str[3] && str[4] == str[5]) {
        flag = 1;
    }
    flag == 1 ? cout << "Yes" : cout << "No";
    return 0;
}