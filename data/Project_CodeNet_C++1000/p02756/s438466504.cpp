#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    string s;
    int q;
    cin>>s>>q;
    
    deque<char> dq;
    rep(i,s.size()){
        dq.push_back(s[i]);
    }

    bool rev=false;
    while(q--){
        int t;
        cin>>t;
        if(t==1) rev=!rev;
        else{
            int f;
            char c;
            cin>>f>>c;
            if(f==1){
                if(rev) dq.push_back(c);
                else dq.push_front(c);
            }
            else{
                if(!rev) dq.push_back(c);
                else dq.push_front(c);
            }
        }
    }

    if(rev) reverse(all(dq));
    while(!dq.empty()){
        char ans=dq.front();
        dq.pop_front();
        cout<<ans;
    }
    cout<<endl;
}