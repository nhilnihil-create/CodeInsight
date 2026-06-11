#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int n;

void dfs(string s,char la){
    if(s.size()==n){
        cout<<s<<endl;
        return;
    }

    for(char c='a';c<=la;c++){
        if(c==la && c!='z') dfs(s+c,char(c+1));
        else dfs(s+c,la);
    }
}

int main() {
    cin>>n;

    dfs("a",'b');
}

