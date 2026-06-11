#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
    int h,w,ans=0;cin>>h>>w;
    vector<string> s(h);
    REP(i,h) cin>>s.at(i);
    vector<vector<int>> hh(h,vector<int>(w,0)),ww(h,vector<int>(w,0));

    REP(i,h){
        int l=0;
        while(l<w){
            if(s.at(i).at(l)=='#') l++;
            else{
                int r=l,count=0;
                while(r<w&&s.at(i).at(r)=='.'){
                    r++;
                    count++;
                }
                for(int j=l;j<r;j++) hh.at(i).at(j)=count;
                l=r;
            }
        }
    }

    REP(j,w){
        int l=0;
        while(l<h){
            if(s.at(l).at(j)=='#') l++;
            else{
                int r=l,count=0;
                while(r<h&&s.at(r).at(j)=='.'){
                    r++;
                    count++;
                }
                for(int i=l;i<r;i++) ww.at(i).at(j)=count;
                l=r;
            }
        }
    }

    REP(i,h) REP(j,w) ans=max(ans,hh.at(i).at(j)+ww.at(i).at(j));
    cout<<ans-1;
}
