#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using P=pair<int,int>;
using ll=long long;

int main(){
    ll A,V,B,W,T;
    cin>>A>>V>>B>>W>>T;
    cout<<(abs(A-B)<=(V-W)*T?"YES":"NO")<<endl;
}
