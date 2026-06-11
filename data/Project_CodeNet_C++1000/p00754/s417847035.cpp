#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS=1e-10;
const ll INF=1000000000;
int main(){
    string s;
    while(1){
        getline(cin,s);
        if(s=="."){
            break;
        }
        stack<char> st;
        bool f=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['){
                st.push(s[i]);
            }else if(s[i]==')'){
                if(st.empty()){
                    f=false;
                    break;
                }
                if(st.top()=='('){
                    st.pop();
                }else{
                    f=false;
                    break;
                }
            }else if(s[i]==']'){
                if(st.empty()){
                    f=false;
                    break;
                }
                if(st.top()=='['){
                    st.pop();
                }else{
                    f=false;
                    break;
                }
            }
        }
        if(!st.empty()){
            f=false;
        }
        if(f){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
