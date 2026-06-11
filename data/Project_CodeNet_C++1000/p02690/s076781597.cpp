#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define mod 1000000007 //10^9+7
#define INF 1000000000000 //10^12
#define F first
#define S second
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()
int x;
vector<int>vec;
set<int>st;
signed main(){
    cin>>x;
    for(int i=-999;i<=999;i++){
        vec.push_back(i*i*i*i*i);
        st.insert(i*i*i*i*i);
    }
    for(int i=0;i<2000;i++){
        int dif=vec[i]-x;
        if(st.find(dif)!=st.end()){
            rep(j,2000){
                if(vec[j]==dif){
                    cout<<i-999<<" "<<j-999<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}

