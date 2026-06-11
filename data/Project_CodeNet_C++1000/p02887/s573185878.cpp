#include <bits/stdc++.h>
#define rep(i,n) for(int i = 1; i < (n); ++i )
typedef std::pair<int,int> pint;

using namespace std;
typedef long long ll;

int main(){
    int N; cin >> N;
    string str; cin >> str;
    string ans;
    char tmp;
    tmp = str[0];
    ans[0] = tmp;
    //cout << ans[0] << endl;
    rep (i,str.length()){
        if (str[i] == tmp){
            continue;
        }
        else{
            tmp = str[i];
            ans += tmp;
        }
    }
    //cout << ans << endl;
    cout << ans.length() + 1 << endl; 
    return 0;
}