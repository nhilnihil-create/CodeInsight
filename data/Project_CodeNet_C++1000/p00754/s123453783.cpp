#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

void solve(string& s){
    int n=s.size();
    stack<char> st;
    st.push('a');
    rep(i,n){
        if(s[i]=='(')st.push('(');
        if(s[i]=='[')st.push('[');
        if(s[i]==')'){
            if(st.top()=='(')st.pop();
            else{
                cout<<"no"<<endl;
                return ;
            }
        }
        if(s[i]==']'){
            if(st.top()=='[')st.pop();
            else{
                cout<<"no"<<endl;
                return ;
            }
        }
    }
    if(st.size()==1)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
int main(){
    string s;
    while(getline(cin,s),s!=".")solve(s);
    return 0;
}
