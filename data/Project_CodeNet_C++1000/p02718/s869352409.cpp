#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    int sum=0;
    rep(i,n){
        cin>>a.at(i);
        sum+=a.at(i);
    }
    int count=0;
    rep(i,n){
        if(a.at(i)*4*m>=sum){
            count++;
        }
    }
    if(count>=m){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}