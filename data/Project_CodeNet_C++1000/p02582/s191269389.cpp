#include<bits/stdc++.h>
using namespace std;
#define lli long long int
# define rep(i,n) for(int i=0;i<n;i++)
// void solve(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     rep(i,n)
//     cin>>a[i];
//     sort(a.begin(),a.end());


// }

void solve(){
    string s;
    cin>>s;
    int mx =0;
    int cnt =0 ;
    for(int i=0;i<3;i++){
        if(s[i]=='R')
        cnt++;
        else{
            mx = max(mx,cnt);
            cnt = 0;
        }
    }
    mx = max(cnt,mx);
    cout<<mx<<endl;
}


int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
}