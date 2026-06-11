#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    string ABC = "ABC";
    cin >> N;
    string input_str;
    cin >> input_str;
    ll sum = 0;
    for (ll i = 0; i < N - 2; i++) {
        for(ll j = 0; j < 3; j++) {
            if (input_str[j + i] == ABC[j])
            {
                if (j == 2) {
                    sum++;
                }
            } else {
                break;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
