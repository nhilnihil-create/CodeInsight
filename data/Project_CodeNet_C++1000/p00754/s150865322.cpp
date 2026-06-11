#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

#define REP(i, x) for(int i=0;i<(int)(x);i++)
#define REPS(i, x) for(int i=1;i<=(int)(x);i++)
#define RREP(i, x) for(int i=(int)(x)-1;i>=0;i--)
#define RREPS(i, x) for(int i=(int)(x);i>0;i--)
#define FOR(it, x) for(auto it=x.begin();it!=x.end();++it)
#define pb push_back
typedef long long ll;
typedef vector<int> vi;

int n, p[300000];

int solve(string s){
        vector<char> st(1, '#');
        FOR(q, s){
                char c = *q;
                if(c == '(' || c == '[') st.pb(c);
                if(c == ')'){
                        if(st.back() != '(') return 0;
                        st.pop_back();
                }
                if(c == ']'){
                        if(st.back() != '[') return 0;
                        st.pop_back();
                }
        }       
        return st.size() == 1;
}

int main(){
        string s;
        while(getline(cin, s), s != "."){
                cout << (solve(s) ? "yes" : "no") << endl;
        }
        return 0;
}