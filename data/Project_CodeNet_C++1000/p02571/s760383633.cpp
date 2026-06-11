#include<iostream>
using namespace std;
int main() {
    string S, T;
    cin >> S >> T;

    int max = 0;
    for(int i = 0; i <= (int)S.size() - (int)T.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < (int) T.size(); j++) {
            if (S[i + j] == T[j]) cnt++;
        }
        if (max < cnt) max = cnt;
    }
    int ret = (int)T.size() - max;
    cout << (ret) << endl;

    return 0;
}
