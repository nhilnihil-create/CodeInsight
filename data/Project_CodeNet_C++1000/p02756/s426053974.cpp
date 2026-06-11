#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    string s;
    int q;
    cin>>s>>q;
    deque<char> dq;
    int n=s.size();
    rep(i,n) dq.push_back(s[i]);
    int t,f,top=0;
    char c;
    rep(i,q){
        cin>>t;
        if(t==1){
            if(top==0) top=n-1;
            else top=0;
        }
        else{
            cin>>f>>c;
            if(f==1){
                if(top==0) dq.push_front(c);
                else dq.push_back(c);
            }
            else{
                if(top==0) dq.push_back(c);
                else dq.push_front(c);
            }
            n++;
        }
    }
    if(top!=0) reverse(all(dq));
    rep(i,n) cout<<dq[i];
}