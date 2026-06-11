#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

int main(void){
    int n,m,p;
    while(cin>>n>>m>>p,n){
        double t=0,h=0;
        rep(i,n){
            int s; cin>>s;
            if(i+1==m)h=s;
            t+=s;
        }
        cout<<floor(h?t*(100-p)/h:0)<<endl;
    }
}