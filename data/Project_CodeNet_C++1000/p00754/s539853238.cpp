#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define MP make_pair
#define INF (sizeof(int) == 4 ? 1e9:1e18)
#define EPS 0.0000000001
using namespace std;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
template<class T> void join(T a){int b=0;for(auto itr :a){if(b++!=0)cout << " "; cout << itr;} }
using ll  = long long;
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
#define int ll
signed main(){
    string s;
    while(getline(cin,s),s!="."){
        bool flag = true;
        stack<char>st;
        rep(i,s.size()){
            if(s[i] == '(' || s[i] == '['){
                st.push(s[i]);
                continue;
            }
            if(s[i] == ')' || s[i] == ']'){
                if(st.empty())flag = false;
                else if(st.top() == '(' && s[i] == ')'){
                    st.pop();
                    continue;
                }else if(st.top() == '[' && s[i] == ']'){
                    st.pop();
                    continue;
                }else flag = false;
            }
        }
        cout << (flag && st.empty() ?  "yes":"no") << endl;
    }
}


