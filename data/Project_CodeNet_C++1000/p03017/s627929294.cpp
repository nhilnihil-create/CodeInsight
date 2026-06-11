#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int n,a,b,c,d;
    cin >>n>>a>>b>>c>>d;
    string s;cin >>s;
    a--;b--;c--;d--;
    bool sunuke=true;
    bool hunuke=true;
    int now=0;
    for (int i = 0; i < n; ++i) {
        if(i<a)continue;
        if(i>c)break;
        if(s[i]=='#')now++;
        else {
            if(now>=2)sunuke=false;
            now=0;
        }
    }
    if(now>=2)sunuke=false;
    swap(a,b);
    swap(c,d);
    now=0;
    for (int i = 0; i < n; ++i) {
        if(i<a)continue;
        if(i>c)break;
        if(s[i]=='#')now++;
        else {
            if(now>=2)hunuke=false;
            now=0;
        }
    }
    swap(a,b);
    swap(c,d);
    now=0;
    bool flg=false;
    if(c>d){
        for (int i = b-1; i <=d+1; ++i) {
            if(s[i]=='.')now++;
            else {
                if(now>=3)flg=true;
                now=0;
            }
        }
        if(now>=3)flg=true;
    }
    if(c<d){
        if(sunuke&&hunuke)puts("Yes");
        else puts("No");
    }
    else {
        if(sunuke&&hunuke&&flg)puts("Yes");
        else puts("No");
    }
}
