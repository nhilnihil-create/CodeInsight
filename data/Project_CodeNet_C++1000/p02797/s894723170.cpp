#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    long long N,K,S; cin >> N >> K >> S;
    if(S==pow(10,9)){
        for(int i=0;i<N;i++){
            if(i<K) cout << S <<' ';
            else cout << 1 << ' ';
        }
    }else {
        for(int i=0;i<N;i++){
            if(i<K) cout << S <<' ';
            else cout << S+1 << ' ';
        }
    }
}
