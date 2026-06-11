#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

char inttochar(int a){
    if(a==0) return'a';
    if(a==1) return'b';
    if(a==2) return'c';
    if(a==3) return'd';
    if(a==4) return'e';
    if(a==5) return'f';
    if(a==6) return'g';
    if(a==7) return'h';
    if(a==8) return'i';
    if(a==9) return'j';
    if(a==10) return'k';
    if(a==11) return'l';
    if(a==12) return'm';
    if(a==13) return'n';
    if(a==14) return'o';
    if(a==15) return'p';
    if(a==16) return'q';
    if(a==17) return'r';
    if(a==18) return's';
    if(a==19) return't';
    if(a==20) return'u';
    if(a==21) return'v';
    if(a==22) return'w';
    if(a==23) return'x';
    if(a==24) return'y';
    if(a==25) return'z';
}
ll sum26(ll n){
    ll a=pow(26,n)-1;
    return 26*a/25;
}

int main(){
    ll n;
    cin>>n;
    n--;
    int limit=1;
    while(sum26(limit)<=n){
        limit++;
    }
    //limitが桁数

    ll think=n-sum26(limit-1);
    vector<char> preans;
    rep(i,limit){
        preans.push_back(inttochar(think%26));
        think/=26;
    }
    string s;
    per(i,limit){
        s+=preans[i];
    }
    cout<<s<<endl;
}