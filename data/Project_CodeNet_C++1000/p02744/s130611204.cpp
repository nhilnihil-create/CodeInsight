#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(void){
    int N;
    cin >> N;
    queue<pair<string,char>> ans;
    
    ans.push(make_pair("a", 1));
    pair<string, int> tmp;
    while(ans.front().first.size() != N){
        tmp = ans.front();
        for(int i = 0; i < tmp.second; i++){
            ans.push(make_pair(tmp.first + (char)('a' + i) , tmp.second));
        }
        ans.push(make_pair(tmp.first + (char)('a' + tmp.second) , tmp.second + 1));
        ans.pop();
    }
    while(!ans.empty()){
        printf("%s\n", ans.front().first.c_str());
        ans.pop();
    }
    
    
    
}
