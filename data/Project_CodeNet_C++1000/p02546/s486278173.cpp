#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
typedef long long ll;

int main(){
    string s; cin>>s;
    int ls = s.size();
    if(s[ls-1]=='s'){
        cout << s << "es" << endl;
    }else{
        cout << s << 's' << endl;
    }
}