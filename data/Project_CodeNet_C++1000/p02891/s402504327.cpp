#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    string S; cin >> S; string S2 = S+S;
    long long K; cin>>K;

    int len=1;
    for(int i=1;i<S.size();i++){if(S[i]==S[i-1])len++;}
    if(len==S.size()) cout << (len*K)/2 << endl;
    else{
        long long count=1;
        long long T=0;
        for(int i=1;i<S.size();i++){
            if(S[i]==S[i-1])count++;
            else {T+=count/2; count=1;}
        }
        T+= count/2;

        count=1;
        long long T2=0;
        for(int i=1;i<S2.size();i++){
            if(S2[i]==S2[i-1])count++;
            else {T2+=count/2; count=1;}
        }
        T2+= count/2;
        long long ans = (T2-T)*(K-1)+T;

        cout << ans << endl;
    }
}

