#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    string s;
    int q;
    
    cin>>s>>q;
    
    deque<char> deq;
    
    rep(i,s.size())deq.push_back(s[i]);
    int par = 0;
    
    rep(i,q){
        int t; cin>>t;
        
        if(t==1){
            par++;
            continue;
        }
        
        int f; cin>>f;
        char c; cin>>c;
        
        if((f+par)%2)deq.push_front(c);
        else deq.push_back(c);
        
    }
    
    if(par%2){
        while(!deq.empty()){
            cout << deq.back();
            deq.pop_back();
        }
    }else{
        while(!deq.empty()){
            cout << deq.front();
            deq.pop_front();
        }
    }
    cout << endl;
    
    return 0;
}