#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int main(){
    string s;
    while(getline(cin,s),s!="."){
        stack<int> st;
        bool ans=true;
        int n=s.size();
        --n;
        int c1=0,c2=0;
        rep(i,n){
            if(s[i]=='('){
                ++c1;
                st.push(0);
            }
            else if(s[i]=='['){
                ++c2;
                st.push(1);
            }
            else if(s[i]==')'){
                --c1;
                if(c1<0||st.top()==1) ans=false;
                st.pop();
            }
            else if(s[i]==']'){
                --c2;
                if(c2<0||st.top()==0) ans=false;
                st.pop();
            }
            if(!ans) break;
        }
        if(ans&&c1==0&&c2==0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
