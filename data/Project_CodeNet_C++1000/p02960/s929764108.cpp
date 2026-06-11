#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s;
    cin >> s;
    ll n;
    n=s.size();
    vector <ll> ans(13,0),ans2(13,0);
    ans[0]=1;
    string h;
    ll t,z;
    rep(i,n){
        //rep(j,13) cout << ans[j];
        //cout << endl;
        if(s[n-i-1]=='?'){
            rep(j,13){
                ans2[j]=0;
            }
            if((i+1)%6==1){
                z=1;
            }
            else if((i+1)%6==2){
                z=10;
            }
            else if((i+1)%6==3){
                z=9;
            }
            else if((i+1)%6==4){
                z=12;
            }
            else if((i+1)%6==5){
                z=3;
            }
            else if((i+1)%6==0){
                z=4;
            }
            rep(j,13){
                rep(k,10){
                    ans2[(j+k*z)%13]+=ans[j];
                }
            }
           
        }
        else{
            h=s[n-i-1];
            t=stoi(h);
            if((i+1)%6==1){
                z=t;
            }
            else if((i+1)%6==2){
                z=(10*t)%13;
            }
            else if((i+1)%6==3){
                z=(9*t)%13;
            }
            else if((i+1)%6==4){
                z=(12*t)%13;
            }
            else if((i+1)%6==5){
                z=(3*t)%13;
            }
            else if((i+1)%6==0){
                z=(4*t)%13;
            }

            rep(j,13){
                ans2[(j+z)%13]=ans[j];
            }

            
            


        }
        rep(j,13){
            ans[j]=(ans2[j]%1000000007);
        }
    }

    cout << ans[5] << endl;
    

    return 0;
}