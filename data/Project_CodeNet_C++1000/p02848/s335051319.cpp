#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.length();
    string a;
    rep(i, len){
        int x = s[i]-'A';
        x= (x+n) % 26;
        a = x+'A';
        cout << a;
    }
    return 0;
}