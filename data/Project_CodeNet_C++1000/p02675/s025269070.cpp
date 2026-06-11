#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n ;cin>>n;
    string s;
    s=to_string(n);
    int x =s[s.size()-1]-'0';
    if(x==3){
        cout<<"bon"<<endl;

    }
    else if(x==0||x==1||x==6||x==8){
        cout<<"pon"<<endl;

    }
    else cout<<"hon"<<endl;


}