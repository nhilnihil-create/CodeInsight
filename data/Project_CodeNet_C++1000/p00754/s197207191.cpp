#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<iomanip>
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define loop(i,a,b) for(long long i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;
typedef long long ll;
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<string> vs;
Def inf=1e9;
signed main(){
    string s;
    while(getline(cin,s),s!="."){
        stack<int>st;
        bool h=true;
        rep(i,s.size()){
            if(s[i]=='('){
                st.push(0);
            }else if(s[i]==')'){
                if(st.size()&&st.top()==0){
                    st.pop();
                }else{
                    h=false;
                    break;
                }
            }else if(s[i]=='['){
                st.push(1);
            }else if(s[i]==']'){
                if(st.size()&&st.top()==1){
                    st.pop();
                }else{
                    h=false;
                    break;
                }
            }
        }
        if(st.size())h=false;
        if(h)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}

