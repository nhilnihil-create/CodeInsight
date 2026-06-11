#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;


int main(){
int n;
cin>>n;
    vector<int> p(n);
    vector<int> q(n);
    int countp=0;
    int countq=0;
    
    rep(i,n)cin>>p[i];
    rep(i,n)cin>>q[i];
    while(prev_permutation(p.begin(),p.end())){
countp++;
    }
    while(prev_permutation(q.begin(),q.end())){
countq++;
    }
    cout<<abs(countp-countq)<<endl;
    
    return 0;

}
