#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
typedef long long ll;
typedef pair<int,int> P;

template<typename A,typename B> inline void chmin(A &a,B b){if(a>b) a=b;}
template<typename A,typename B> inline void chmax(A &a,B b){if(a<b) a=b;}
//-----------------------------------------------------------------------

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    while(true)
    {
        getline(cin,s);
        if(s[0]=='.') break;

        stack<char> St;

        bool ok=true;
        REP(i,s.size()){
            if(s[i]=='(') St.push(s[i]);
            if(s[i]=='[') St.push(s[i]);
            if(s[i]==')'){
                if(St.empty() || St.top()!='('){ ok=false;break;}
                else St.pop();
            }
            if(s[i]==']'){
                if(St.empty() || St.top()!='['){ ok=false;break;}
                else St.pop();
            }
        }
        if(!St.empty()) ok=false;
        cout<<(ok?"yes":"no")<<endl;

    }
}