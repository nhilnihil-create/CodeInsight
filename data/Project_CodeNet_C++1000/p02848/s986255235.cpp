#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        s[i] = (s[i]-'A' + n)%26 + 'A';
    }
    cout << s << endl;
   return 0;
}