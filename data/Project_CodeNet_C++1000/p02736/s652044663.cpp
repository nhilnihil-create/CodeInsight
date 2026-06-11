#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> one, two;
    string s;
    bool flg = true;
    cin >> n >> s;
    --n;
    for(int i=0;i<=n;++i){
        int d = s[i] - '1';
        one.emplace_back(d & 1);
        two.emplace_back(d == 2);
        if(d & 1) flg = false;
    }
    int ans = 0;
    for(int i=0;i<=n;++i){
        if((n&i) == i) ans += one[i];
    }
    if(ans & 1){ cout << 1 << endl; return 0; }
    if(!flg){ cout << 0 << endl; return 0; }
    ans = 0;
    for(int i=0;i<=n;++i){
        if((n&i) == i) ans += two[i];
    }
    if(ans & 1){ cout << 2 << endl; return 0; }
    cout << 0 << endl;

    return 0;
}