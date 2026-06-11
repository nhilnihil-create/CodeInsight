#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )
typedef std::pair<int,int> pint;

using namespace std;
typedef long long ll;

int main(){
    int N; cin >> N;
    string str; cin >> str;
    int length = str.length();
    int red_count = 0;
    int white_count = 0;
    int ans;
    rep (i,length){
        if (str[i] == 'R'){
            red_count++;
        }
    }
    rep (i,red_count){
        if (str[i] == 'W'){
            white_count++;
        }
    }
    ans = min(red_count,white_count);
    cout << ans << endl;
}