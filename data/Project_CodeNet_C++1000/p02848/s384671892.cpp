#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int searchIndex(vector<char> s, char item) { for (int i = 0; i < s.size(); ++i) if (s[i] == item) return i;}

int main() {
    vector<char> alphabets = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',  'Z'};
    int n;
    string s;
    cin >> n >> s;
    for (char & i : s) {
        int index = searchIndex(alphabets, i);
        i = alphabets.at(index + n > 25 ? index + n - 26 : index + n);
    }
    cout << s << endl;
}
