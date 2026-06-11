#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;

int main(void){
    // Your code here!
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    if(s[0] == '2' || s[0] == '4' || s[0] == '5' || s[0] == '7' || s[0] == '9'){
        cout << "hon" << endl;
    }
    if(s[0] == '0' || s[0] == '1' || s[0] == '6' || s[0] == '8'){
        cout << "pon" << endl;
    }
    if(s[0] == '3'){
        cout << "bon" << endl;
    }
    return 0;
}