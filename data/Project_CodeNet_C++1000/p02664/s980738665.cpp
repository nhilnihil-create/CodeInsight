#include <bits/stdc++.h>
#include <math.h>


    using namespace std;
    typedef long long ll;
    # define M_PI  3.14159265358979323846
    const int MOD=1e9+7;

    void solve(){
        string s;
        cin>>s;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='?' && ((i+1<n && s[i+1]=='P') || (i-1>=0 && s[i-1]=='P'))){
                s[i]='D';
            }
            else if(s[i]=='?' && i+1<n && s[i+1]=='?'){
                s[i]='P';
                s[i+1]='D';
            }
            else if(s[i]=='?' && i+1<n && s[i+1]=='D')
                s[i]='P';
            else if(s[i]=='?')
                s[i]='D';
        }
        cout<<s;
        
//        for(int i=0;i<n;i++){
//            if(s[i]=='?')
//                s[i]='D';
//        }
//        cout<<s;
    }

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
        int t=1;
//        cin>>t;
        for(int i=1;i<=t;i++){
            solve();
        }
        return 0;
    }
