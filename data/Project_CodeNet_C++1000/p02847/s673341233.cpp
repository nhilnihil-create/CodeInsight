
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    int a;
    if(s=="SUN")a=7;
    else if(s=="MON")a=6;
    else if(s=="TUE")a=5;
    else if(s=="WED")a=4;
    else if(s=="THU")a=3;
    else if(s=="FRI")a=2;
    else a=1;
    cout << a << endl;

}