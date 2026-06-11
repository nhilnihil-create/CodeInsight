
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    if(s[0]==s[1] || s[1]==s[2] || s[2]==s[3]){
        cout << "Bad" << endl;
        return 0;
    }
    cout << "Good" << endl;
}