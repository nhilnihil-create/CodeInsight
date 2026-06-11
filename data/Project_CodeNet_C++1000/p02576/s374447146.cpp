#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,X,T;
    int ans,tmp;

    cin >> N >> X >> T;
    ans = N / X;
    tmp = N % X;

    if (tmp != 0){
        ans++;
    }
    cout << ans * T << endl;
}