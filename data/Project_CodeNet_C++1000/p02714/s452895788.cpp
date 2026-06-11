#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main() {
    int N;
    string S;
    cin >>N>>S;
    vector<int> R,G,B;
    rep(i,N){
        string a = S.substr(i,1);
        if (a =="R") R.push_back(i);
        if (a =="G") G.push_back(i);
        if (a =="B") B.push_back(i);
    }
    ll err=0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(S[i]!=S[j]){
                if(2*j-i<=N-1){
                    if(S[i]!=S[2*j-i]&&S[j]!=S[2*j-i]) err++;
                }
            }
        }
    }
    cout << R.size()*G.size()*B.size()-err;
}