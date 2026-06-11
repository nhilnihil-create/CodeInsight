#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    string s;
    cin >> s;
    bool flag = true;
    for(int i=0;i<s.size();i++){
        if((i+1) % 2 == 1){
            if(s[i] == 'R' || s[i] == 'U' || s[i] == 'D'){
                //cout << s[i] << endl;
                continue;
            }else{
                flag = false;
                break;
            }
        }else{
            if(s[i] == 'L' || s[i] == 'U' || s[i] == 'D'){
                //cout << s[i] << 2 << endl;
                continue;
            }else{
                flag = false;
                break;
            }
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}