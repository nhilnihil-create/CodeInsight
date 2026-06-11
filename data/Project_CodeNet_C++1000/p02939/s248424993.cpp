// lcmとかはg++ -std=c++17 default.cppみたいなかんじで
//vector<vector<ll>> piyo(tate,vector<ll> (yoko));

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 100000001
#define ll long long
#define ln cout<<endl;
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
int dp[120][1050];
bool my_compare(pair<ll, string> a, pair<ll , string> b) {
    // 基本はfirstで比較
    if(a.first != b.first){
         //return a.first < b.first; // 昇順
        return a.first > b.first; // 降順
    }

    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        // どちらも同じ
        return true;
    }
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    //double mini=INF;
    int maxi=0,f=0,sum=0,mini=INF;
    string str,str1,str2;
    int i;
    int n;
    int a,b,d,c;
    int e,weight;
    vector<pair<ll,string>> p;
    cin>>str;
    char last='A';
    rep(i,str.length()){
        if(last!=str[i]) {
            sum++;
            if(f==1) last='A';
            else last=str[i];
            f=0;
            }
        else {
            f=1;
            last='A';
            }
        //else i++;
    }
    cout<<sum<<endl;
    return 0;
}
