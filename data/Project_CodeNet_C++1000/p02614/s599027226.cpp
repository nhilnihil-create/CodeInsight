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

int main(){
    int h,w,k;
    cin>>h>>w>>k;
    vector<string> field;
    rep(i,h){
        string s;
        cin>>s;
        field.push_back(s);
    }
    
    vector<string> field2;
    int ans=0;
    for(int bit1=0; bit1<(1<<h); bit1++){
        for (int bit2=0; bit2<(1<<w); bit2++){
            field2=field;
            rep(i,h){
                if(bit1&(1<<i)) {
                    rep(j,w){
                        field2[i][j]='.';
                    }
                }
            }
            rep(i,w){
                if(bit2&(1<<i)) {
                    rep(j,h){
                        field2[j][i]='.';
                    }
                }
            }
            //check
            int count=0;
            rep(i,h){
                rep(j,w){
                    if(field2[i][j]=='#') count++;
                }
            }
            if(count==k) ans++;
        }
    }
    cout<<ans<<endl;

}