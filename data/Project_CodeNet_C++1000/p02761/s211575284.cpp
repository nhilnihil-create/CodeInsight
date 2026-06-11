#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)


int main(){
    int N,M;
    cin >> N >> M;

    if(N==1&&M==0){
        cout << 0 << endl;
        return 0;
    }

    vector<int> s(M),c(M);
    vector<int> num(N);
    rep(i,N) num[i]=-1;
    //num[0]=0;
    

    rep(i,M){
        cin >> s[i] >> c[i];
    }

    

    rep(i,M){
        if(num[s.at(i)-1] == -1 || num[s.at(i)-1] == c.at(i)){
            num[s.at(i)-1] = c.at(i);
        }else{
            cout << -1 << endl;
            return 0;
        }

    }

    if(num[0]==0){
        if(N!=1){
        cout << -1 << endl;
        return 0;
        }
    }else if(num[0]==-1){
        num[0]=1;
    }

    

    rep(i,N){
        if(num[i]==-1) num[i] = 0;
        cout << num[i];
    } 

    

    cout << '\n';

}