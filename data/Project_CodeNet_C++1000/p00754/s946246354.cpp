#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        if(s==".")break;
        stack<char>st;
        for(auto x:s){
            if(x=='(')st.push(x);
            if(x=='[')st.push(x);
            if(x==')'){
                if(!st.empty() && st.top()=='(')st.pop();
                else{
                    st.push(x);
                    break;
                }
            }
            if(x==']'){
                if(!st.empty() && st.top()=='[')st.pop();
                else{
                    st.push(x);
                    break;
                }
            }
        }
        if(st.empty())cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}