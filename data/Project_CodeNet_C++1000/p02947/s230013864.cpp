#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;

int main(){
    int n;
    cin>>n;

    vector<string>s(n);
    rep(i,n){
        cin>>s[i];
        sort(s[i].begin(),s[i].end());
    }

    sort(s.begin(),s.end());
    s.push_back("");

    ll cnt=1,ans=0;

    rep(i,n){
        if(s[i]==s[i+1]){cnt++;}
        else {
            ans+=(cnt*(cnt-1))/2;
            cnt=1;

        }
    }

    cout<<ans<<endl;

}
