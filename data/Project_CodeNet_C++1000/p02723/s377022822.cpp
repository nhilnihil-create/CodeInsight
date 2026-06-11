#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    char s[6];
    cin >> s;
    if (s[2]==s[3]&&s[4]==s[5]){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}