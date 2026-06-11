#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
int main(){
    string s;
    cin >> s;
    bool ans = true;
    if(s.size() % 2 == 0){
        rep(i,s.size()){
            if(s[i] != 'h' || s[i+1] != 'i'){
                ans = false;
                break;
            }
            i++;
        }
    }
    else ans = false;
    cout << (ans? "Yes" : "No") << endl;
    return 0;
}