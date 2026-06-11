#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<set>
#include<stack>
#include<complex>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define CC puts("-------ok--------");
#define all(in) in.begin(), in.end()
#define bv vector<bool>
using namespace std;
typedef pair<int, int>PA;
using namespace std;
#define MAX  999999
int main(){
    string s;
    while(getline(cin,s)){
        if(s.size()==1&&s[0]=='.') break;
        stack<char>st;
        bool check=true;
        rep(i,s.size()){
            if(s[i] =='(' || s[i] == '[')
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty()) check=false;
                else if(st.top()=='(') st.pop();
                else check=false;
            }else if(s[i]==']'){
                if(st.empty())check=false;
                else if(st.top()=='[')st.pop();
                else check=false;
            }
            if(!check) break;
        }
        if(st.empty() &&check) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}