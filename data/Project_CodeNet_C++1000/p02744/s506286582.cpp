#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int n;
vector<string> ans;

void dfs(string s, char mxc){
    if(s.size() == n){
        ans.push_back(s);
        return;
    }
    char adc = 'a'-1;
    while(true){
        adc++;
        string t = s + adc;
        dfs(t, max(adc,mxc));
        if(adc == mxc+1) break;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    dfs("a", 'a');

    for(auto a : ans){
        cout<<a<<endl;
    }
    
}