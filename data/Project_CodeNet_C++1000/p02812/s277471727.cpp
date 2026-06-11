#include <iostream>
using namespace std;

int main() {

    int N;
    string S;
    int cnt = 0;

    cin >> N >> S;

    for (int i = 0; i < N - 2; i++) {

        // substr(開始位置, 取り出す長さ);
        string ss = S.substr(i, 3);
        if (ss == "ABC"){
            cnt++;
        }
    }
    cout << cnt << endl;
    
    return 0;

}