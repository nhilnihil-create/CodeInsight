#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


//panasonic programming contest 2020 d

void dfs(string S,int n,string lis){
    if(S.size()==n) cout << S << endl;
    else{
        for(auto c : lis){
            S.push_back(c);
            dfs(S,n,lis);
            S.pop_back();
        }
        char last = lis[lis.size()-1]+1;
        S.push_back(last);
        lis.push_back(last);
        dfs(S,n,lis);
    }
}


int main(){
    int n;
    cin >> n;
    string s = "a";
    dfs(s,n,s);
}


