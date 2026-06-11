#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
const int MOD = 1000000007;

int main(){
    
    int n; cin >> n;
    
    queue<string> s;
    s.push("a");
    
    rep(i,n){
        while(s.front().size()==i){
            string t = s.front();
            set<char> clist;
            for(char c: t){
                clist.insert(c);
            }
            for(int i=0; i<=clist.size(); i++){
                string u = t;
                u += (char)('a'+i);
                s.push(u);
            }
            s.pop();
        }
    }
    
    while(!s.empty()){
        cout<<s.front();
        s.pop();
        if(s.empty())
            cout << endl;
        else
            cout <<" ";
    }
    
    return 0;
}