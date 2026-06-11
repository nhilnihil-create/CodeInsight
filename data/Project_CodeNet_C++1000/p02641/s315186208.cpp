#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int x,n;
    cin>>x>>n;
    int p[n];
    rep(i,n)cin>>p[i];
    int b=x,s=x;
    bool b_flag,s_flag;
    while(1){
        b_flag=false;
        s_flag=false;
        rep(i,n){
            if(s==p[i]){
                s_flag=true;
            }
            if(b==p[i]){
                b_flag=true;
            }
        }
        if(!s_flag){
            cout<<s<<endl;
            break;
        }
        else if(!b_flag){
            cout<<b<<endl;
            break;
        }
        b++;
        s--;
    }

    return 0;
}
