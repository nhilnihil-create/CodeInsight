#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int H,W,K;
    cin>>H>>W>>K;
    vector<vector<char>> c(H,vector<char> (W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>c.at(i).at(j);
        }
    }
    vector<vector<char>> d(H,vector<char> (W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            d.at(i).at(j)=c.at(i).at(j);
        }
    }
    int ans=0;
    for(int bit = 0;bit<(1<<H);++bit){
        for(int BIT = 0;BIT<(1<<W);++BIT){
            for(int i=0;i<H;i++){
                if(bit&(1<<i)){
                    for(int j=0;j<W;j++){
                        d.at(i).at(j)='r';
                    }
                }
            }
            for(int j=0;j<W;j++){
                if(BIT&(1<<j)){
                    for(int i=0;i<H;i++){
                        d.at(i).at(j)='r';
                    }
                }
            }
            int cnt=0;
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    // cout<<d.at(i).at(j)<<" ";
                    if(d.at(i).at(j)=='#'){
                        cnt++;
                    }
                    d.at(i).at(j)=c.at(i).at(j);
                }
                // cout<<endl;
            }
            // cout<<endl;
            if(cnt==K){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}