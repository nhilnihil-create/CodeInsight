#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    int K,A,B; cin >> K >> A >> B;
    if(A%K==0 || B%K==0){
        cout << "OK" << endl;
    }else if(A/K < B/K){
        cout << "OK" << endl;
    }else{
        cout << "NG" << endl;
    }
}