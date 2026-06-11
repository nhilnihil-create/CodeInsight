#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int h,w;
    cin >> h >> w;
    vector <vector <int>> tate(h,vector <int> (w));
    vector <vector <int>> yoko(h,vector <int> (w));
    vector <string> s(h);
    rep(i,h){
        cin >> s[i];
    }
    int k=0,st=0;
    //h kotei
    rep(i,h){
        k=0;
        st=0;
        rep(j,w){
            if(s[i][j]=='.'){
                k+=1;
                if(j==w-1){
                    rep(l,k){
                    yoko[i][st+l]=k;
                }
                }
            }
            else{
                rep(l,k+1){
                    yoko[i][st+l]=k;
                }
                k=0;
                st=j+1;
            }
        }
    }

    k=0;
    st=0;
    //h kotei
    rep(i,w){
        k=0;
        st=0;
        rep(j,h){
            //cout << j << endl;
            if(s[j][i]=='.'){
                k+=1;
                if(j==h-1){
                    rep(l,k){
                    tate[st+l][i]=k;
                }
                }
            }
            else{
                rep(l,k+1){
                    tate[st+l][i]=k;
                }
                k=0;
                st=j+1;
            }
        }
    }

    int ans=-1;
    rep(i,w){
        rep(j,h){
            ans=max(ans,tate[j][i]+yoko[j][i]);
            
        }
    }

    //cout << tate[2][5] << " " << yoko[2][5] << endl;
    cout << ans-1 << endl;


    

    return 0;
}