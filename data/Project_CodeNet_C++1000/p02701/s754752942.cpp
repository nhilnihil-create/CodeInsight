#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ll long long
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
#define BIT_FLAG_1 (1<<1) // 0000 0000 0000 0010
#define BIT_FLAG_2 (1<<2) // 0000 0000 0000 0100
#define BIT_FLAG_3 (1<<3) // 0000 0000 0000 1000
#define BIT_FLAG_4 (1<<4) // 0000 0000 0001 0000
#define BIT_FLAG_5 (1<<5) // 0000 0000 0010 0000
#define BIT_FLAG_6 (1<<6) // 0000 0000 0100 0000
#define BIT_FLAG_7 (1<<7) // 0000 0000 1000 0000

int main(){
    ll n;
    cin >> n;
    set<string> s;
    string str;
    rep(i,n){
        cin >> str;
        s.insert(str);
    }
    cout << s.size() << endl;
}
/*
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
    }
    sort(s.begin(),s.end());
    rep(i,n){
        if(s[i]==s[i+1]){
                s.erase(s.begin()+i);
                i--;
            }
        }
    cout << s.size() << endl;
    }
*/
