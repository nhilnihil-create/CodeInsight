#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    string s;
    cin>>s;
    deque<char> st;
    rep(i, s.size()) st.push_back(s[i]);
    int Q;
    cin>>Q;
    int t, f;
    char c;
    int start=0;
    rep(i, Q){
        cin>>t;
        if(t==1){
            if(start==0) start=-1;
            else start=0;
        }
        if(t==2){
            cin>>f>>c;
            if(f==1){
                if(start==0) st.push_front(c);
                else st.push_back(c);
            }
            if(f==2){
                if(start==0) st.push_back(c);
                else st.push_front(c);
            }
        }
    }

    if(start==0){ 
        rep(i, st.size()){
            cout<<st[i];
        }
    }else{
        rep(i, st.size()){
            cout<<st[st.size()-i-1];
        }
    }
    cout<<endl;
    return 0;
}