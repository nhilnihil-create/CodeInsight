#include<bits/stdc++.h>
using namespace std;
int main(){
    int K,l;
    string S;
    cin >> K >> S;
    l = S.size();
    if(l<=K)cout << S << endl;
    else {
        S = S.erase(K) + "...";
        cout << S << endl;
    }
}