#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 100005
#define ll long long

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << ": " << x << "  "
#else
#define debug(x) ;
#endif
string s;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>s;
    int  f = 0;
    if(s.length()==6){
        if(s[2]==s[3]&&s[4]==s[5])
            f = 1;
    }
    cout<<(f?"Yes\n":"No\n");
    
    
    return 0;
}