#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("../input.txt","r",stdin);
    int N;
    cin >> N;
    
    bool possible = false;
    while(N!=0){
        if(N%10==7){
            possible = true;
            break;
        }
        N/=10;
        
    }
    
    if(possible) cout << "Yes";
    else cout << "No";
}