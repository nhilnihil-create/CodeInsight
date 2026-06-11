#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    string s;
    cin>>s;

    int n=s.size();
    vector<int> ans(n,0);
    int ind,m0=0,m1=0;
    rep(i,n-1){
        if(s[i]=='R' && s[i+1]=='L'){
            ind=i;
            if(i%2==0) m0++;
            else m1++;
        }
        else if(s[i]=='L' && s[i+1]=='R'){
            if(i%2==0) m0++;
            else m1++;
            if(ind%2==0){
                ans[ind]=m0;
                ans[ind+1]=m1;
            }
            else{
                ans[ind]=m1;
                ans[ind+1]=m0;
            }
            m1=0,m0=0;
        }
        else{
            if(i%2==0) m0++;
            else m1++;
        }

        if(i==n-2){
            if((n-1)%2==1) m1++;
            else m0++;
            if(ind%2==0){
                ans[ind]=m0;
                ans[ind+1]=m1;
            }
            else{
                ans[ind]=m1;
                ans[ind+1]=m0;
            }
        }
    }

    rep(i,n) cout<<ans[i]<<" ";
    cout<<endl;
}

