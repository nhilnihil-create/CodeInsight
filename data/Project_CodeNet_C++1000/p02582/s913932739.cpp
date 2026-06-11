#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    string s;
    cin >> s;

    int ans = 0, cnt = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == 'R'){
            cnt++;
        }else{
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);

    cout << ans << "\n";

    return 0;
}