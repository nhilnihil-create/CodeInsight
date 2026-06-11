#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n,a,b,c,d;
string s;

bool solve(int f,int t){
    int now = f;
    while(now!=t){
        if(s[now+1]!='#')now++;
        else if(s[now+2]!='#')now+=2;
        else return false;
    }
    return true;
}
int main(){
    cin >> n >> a >> b >> c >> d;
    a--;b--;c--;d--;
    cin >> s;
    bool ans = false;
    //追い抜きなしのパターン
    if(solve(b,d)){
        s[d]='#';
        if(solve(a,c))ans=true;
        s[d]='.';
    }
    //追い抜きありのパターン
    if(solve(b,d)){
        bool nx=false;
        for(int i = b-1;i<d-1;i++){
            if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.')nx=true;
        }
        if(nx){
            solve(a,c);
            s[c]='#';
            if(solve(b,d))ans=true;
        }
    }
    if(ans)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
