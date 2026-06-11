#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    string buffer;
    vector<int> output;
    int i = 0;
    while (1) {
        while (S[i] != 'L' && i != S.length()) {
            buffer += S[i];
            i++;
        }
        while (S[i] != 'R' && i != S.length()) {
            buffer += S[i];
            i++;
        }
        int count = 0;
        for (int i = 0; i < buffer.length(); i++) {
            if (buffer[i] == 'R') {
                count++;
            }
        }
        int right = 0;
        int left = 0;
        right += count / 2;
        right += (buffer.length() - count + 1) / 2;
        left = buffer.length() - right;
        for (int i = 0; i < count - 1; i++) {
            output.push_back(0);
        }
        output.push_back(left);
        output.push_back(right);
        for (int i = 0; i < buffer.length() - count - 1; i++) {
            output.push_back(0);
        }
        /**/
        buffer = "";
        if (i == S.length()) {
            break;
        }
    }

    for (int i = 0; i < output.size(); i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}
