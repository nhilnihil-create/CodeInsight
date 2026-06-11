#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

vector<string> ans;

void dfs(int n){
    string a = "a";
    queue<string> que;
    que.push("a");
    if(n == 1){
        ans.push_back(a);
        return;
    }
    while(!que.empty()){
        string tmp = que.front(); que.pop();
        int can = 0;
        for(int i = 0; i < tmp.size(); i++){
            if(can < tmp[i]) can = tmp[i];
        }
        for(int i = 'a'; i <= can+1; i++){
            tmp.push_back(i);
            if(tmp.size() == n) ans.push_back(tmp);
            else que.push(tmp);
            tmp.pop_back();
        }
    }
}

int main(){
    int n;
    cin >> n;
    dfs(n);
    for(auto p:ans){
        cout << p << endl;
    }
    return 0;
}