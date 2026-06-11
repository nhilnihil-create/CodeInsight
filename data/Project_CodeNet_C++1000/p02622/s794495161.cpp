#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    string a, b;
    cin >> a >> b;

    int sum=0;
    rep(i, a.size()){
        if(a.at(i) != b.at(i)) sum++;
    }

    cout << sum << endl;
    return 0;
}