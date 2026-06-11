#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using ll=long long;
using namespace std;
const long MOD=1e9+7;
template<class T>
T lcm(T a,T b){
    return a/__gcd(a,b)*b;
}
template<class T>
void chmin(T &a,T b){
    if(a>b){
        a=b;
    }
}

int main(){
    string s;cin >> s;
    for(int i=0;i<s.size();i++){
        if((i+1)%2==1 && s[i]=='L'){
            cout << "No";
            return 0;
        }else if((i+1)%2==0 && s[i]=='R'){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}