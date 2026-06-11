#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
typedef long long ll;

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    cin>>s;
    for(int i = 0; i < s.length(); i++) {
        if(i%2==1){
            if(s[i]=='R'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        else if(i%2==0){
            if(s[i]=='L'){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}