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
    
    deque<char> deq;
    rep(i,s.size()){
        deq.push_back(s[i]);
    }

    bool rev=false;
    rep(i,q){
        int t;
        cin>>t;
        if(t==1) rev=!rev;
        else{
            int f;
            char c;
            cin>>f>>c;
            if(f==1){
                if(rev) deq.push_back(c);
                else deq.push_front(c);
            }
            else{
                if(rev) deq.push_front(c);
                else deq.push_back(c);
            }
        }
    }

    if(rev) reverse(all(deq));
    for(auto c : deq){
        cout<<c;
    }
    cout<<endl;
}