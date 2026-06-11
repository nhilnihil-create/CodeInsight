#include<bits/stdc++.h>
using namespace std;
#define LL long long int

int N;

void recurse(string current, int maxi) {
    if (current.length() == N) {
        cout << current << endl;
        return;
    }

    for (int c = 0; c <= min(25, maxi + 1); c++)
        recurse(current + (char) (c + 'a'), max(maxi, c));
}

int main() {
    cin >> N;
    recurse("a", 0);
}
