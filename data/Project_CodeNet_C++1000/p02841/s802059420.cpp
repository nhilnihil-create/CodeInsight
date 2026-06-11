#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    vector<int> m(2), d(2);
    rep(i, 2){
        cin >> m.at(i) >> d.at(i);
    }
    
    int flag = 1;
    if(m.at(0) == m.at(1)) flag = 0;

    cout << flag << endl;

    return 0;
}