#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N, K;
    cin>> N >> K;

    ll R, S ,P;
    cin>> R >> S >> P;

    string T;
    cin>> T;

    ll ans = 0;
    vector<bool> v(N, false);
    for(int i=0; i<N; i++){
       
        if(i-K>=0 && T[i]==T[i-K] && !v[i-K]){
            //cout<< i <<" : skip"<<endl;
            v[i] = true;
            continue;
        }
        if(T[i] == 'r'){
            ans += P;
        }else if(T[i] == 's'){
            ans += R;
        }else if(T[i] == 'p'){
            ans += S;
        }
        //cout<< i <<" : "<< ans <<endl;
    }

    cout<< ans <<endl;
    return 0;
}