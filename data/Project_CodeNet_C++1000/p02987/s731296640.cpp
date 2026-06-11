#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    string s;
    cin >> s;
    
    sort(s.begin(),s.end());
    
    if(s[0] == s[1] && s[2] == s[3] && s[1] != s[2])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    
    return 0;
}


