#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main(){
    string s; cin >> s;
    if(s.at(s.size()-1)=='3') cout << "bon" << endl;
    else if(s.at(s.size()-1)=='0' || s.at(s.size()-1)=='1' || s.at(s.size()-1)=='6' || s.at(s.size()-1)=='8')
    cout << "pon" << endl;
    else cout << "hon" << endl;
}