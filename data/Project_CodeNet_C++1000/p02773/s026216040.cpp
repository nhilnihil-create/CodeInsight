#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long

int main(){
    map<string,int> memo;
    int n;
    cin >> n;
    rep(i,n){
        string s;
        cin >> s;
        if(memo.count(s)){
            memo[s]++;
        }else{
            memo[s] = 1;
        }
    }
    int max=0;
    for(auto x :memo){
        if(x.second>max){
            max = x.second;
        }
    }

    for(auto it = memo.begin();it != memo.end();it++){
        if(it->second == max){
            cout << it->first << endl;
        }
    }
}
