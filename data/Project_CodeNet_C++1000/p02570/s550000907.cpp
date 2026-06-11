#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    float D,T,S;
    cin  >> D >> T >> S;

    float Treq = D/S;

    if(Treq<=T)cout << "Yes" << '\n';
    else cout << "No" << '\n'; 
    
}