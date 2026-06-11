#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

bool solve(char c1,char c2){
    if(c1=='(')return c2==')';
    else return c2==']';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1){
        string s;
        getline(cin,s);
        if(s==".")break;
        stack<char> st;
        bool ans=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[')st.push(s[i]);
            else if(s[i]==')' || s[i]==']'){
                if(st.empty())ans=false;
                else{
                    if(solve(st.top(),s[i])){
                        st.pop();
                    }
                    else{
                        ans=false;
                    }
                }
            }
        }
        if(!st.empty())ans=false;
        if(ans)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
