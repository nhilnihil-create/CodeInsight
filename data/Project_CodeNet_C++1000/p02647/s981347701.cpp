#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

vector<int> sim(vector<int> vec,int n){
    vector<int> new_vec(n,0);
    rep(i,n){
        int l = max(0,i-vec[i]);
        int r = min(n-1,i+vec[i]);
        new_vec[l]++;
        if(r+1<n) new_vec[r+1]--;
    }
    REP(i,n-1) new_vec[i]+=new_vec[i-1];
    return new_vec;
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    rep(i,n) cin>>vec[i];

    int lim = min(k,50);

    rep(i,lim){
       vec =  sim(vec,n);
    }

    rep(i,n){
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    return 0;
}