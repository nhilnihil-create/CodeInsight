#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>

using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;

vll z_algorithm(string S){
    if(S.size()==0) return vll(0);
    vll ret(S.size());
    ret[0] = S.size();
    int i = 1, j = 0;
    while (i < S.size()) {
        while (i+j < S.size() && S[j] == S[i+j]) j++;
        ret[i] = j;
        if (j == 0) { ++i; continue;}
        int k = 1;
        while (i+k < S.size() && k+ret[k] < j) {
            ret[i+k] = ret[k];
            k++;
        }
        i += k; j -= k;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    string S;
    cin>>N>>S;
    
    ll ans=0;
    for(int i=0;i<N;i++){
        vll A=z_algorithm(S.substr(i));
        for(int j=0;j<A.size();j++){
            ans=max(ans,min(A[j],(ll)j));
        }
    }
    cout<<ans<<endl;
        
    return 0;
}
