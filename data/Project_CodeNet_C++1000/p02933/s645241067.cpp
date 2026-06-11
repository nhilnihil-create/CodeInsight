#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int n;
    string s;
    cin >> n >> s;
    string res = n >= 3200 ? s : "red";

    cout << res << endl;

}