#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll locate(ll a,vector<ll> b){
    for(ll i=0;i<b.size();i++){
        if(a<b[i])return b[i];
    }
    return 0;
}

int main() {
    
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<ll>> A(10,vector<ll>(0));
    for(ll i=0;i<N;i++){
        A[S[i]-'0'].push_back(i);
    }
    
    ll count=0;
    for(int i=0;i<=9;i++){
        if(!A[i].size())continue;
        for(int j=0;j<=9;j++){
            ll con = locate(A[i][0], A[j]);
            if(!con)continue;
            for(int k=0;k<=9;k++){
                if(locate(con, A[k]))count++;
            }
        }
        
    }
    cout << count << endl;
    
}