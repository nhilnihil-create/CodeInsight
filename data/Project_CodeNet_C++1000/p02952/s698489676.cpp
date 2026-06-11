/*
Uneven Numbers
https://atcoder.jp/contests/abc136/tasks/abc136_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,cnt=0;
    string buff;

    cin >> N;
    for(int i=1; i<=N; i++){
        buff = to_string(i);
        if( buff.size() % 2 == 1 ){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}