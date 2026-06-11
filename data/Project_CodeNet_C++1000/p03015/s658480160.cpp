#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll MAX=100100;



int main(){
  	vector<ll> X(MAX, 0), Y(MAX, 0);
    string S;
    cin>>S;
    int Keta=S.size();
  	X[1]=S.at(0)-'0';
  	Y[1]=1+X[1];
    for(int i=1; i<Keta; i++){
        X[i+1] = X[i] * 3 + Y[i] * (S.at(i)-'0');
        X[i+1] %= MOD;
        Y[i+1] = Y[i] * 2 * (S.at(i)- '0') +  Y [i] * ('1' - S.at(i));
        Y[i+1] %= MOD;
    }
    ll Ans=Y[Keta]+X[Keta];
    Ans%=MOD;
    cout<<Ans<<endl;
    return 0;

}