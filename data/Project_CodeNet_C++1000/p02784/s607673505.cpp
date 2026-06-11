#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    int H,N;
    cin >> H >> N;
    vector<int> A;
    rep(i,N){
        int a;
        cin >>a;
        A.push_back(a);
    }
    int sum =0;
    rep(i,N){
        sum += A[i];
    }

    if(sum >= H){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}