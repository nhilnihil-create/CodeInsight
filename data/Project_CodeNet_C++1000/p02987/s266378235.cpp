
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    map <char,int> m;
    string s;
    cin >> s;
    rep(i,4){
        m[s[i]] ++;
    }
    if(m[s[0]]==2 && m[s[1]]==2 && m[s[2]]==2 && m[s[3]]==2){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;

}