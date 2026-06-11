#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll zero = 0;
ll INF = 10000000000;
 
vector<int> res(string S){
    vector<int> re;
    int tmp = 1;
    for(int i = 1; i < S.size(); i++){
        if( S.at(i) == S.at(i-1) ){
            tmp++;
        }
        else{
            re.push_back(tmp);
            tmp = 1;
        }
    }
    re.push_back(tmp);
    return re;
}
 
int main(){
    string S;
    ll K;
    cin >> S >> K;
    ll fS, fSS;
    fS = 0;
    fSS = 0;
    
    vector<int> resS, resSS;
    resS = res(S);
    resSS = res(S+S);
    
    for(int i: resS){
        fS += i/2;
    }
    for(int i: resSS){
        fSS += i/2;
    }
    ll ans;
    if (resS.size() != 1 || S.size() % 2 == 0){
        ans = (K-1)*(fSS-fS)+fS;
    }
    else{
        ans = S.size()*K/2;
    }
    printf("%lld\n", ans);
}