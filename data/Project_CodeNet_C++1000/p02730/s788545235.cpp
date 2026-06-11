#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;

int main(){
    string S;
    cin >> S;
    int n=S.size();
    
    rep(i, (n-1)/2){
        if(S.at(i)!=S.at(n-i-1)){
            cout << "No" << endl;
            return 0;
        }
    }
    if(n%2==0){
        rep(i, ((n-1)/2-1)/2){
            if(S.at(i)!=S.at((n-1)/2-i-1)){
                cout << "No" << endl;
                return 0;
            }
        }
    }else{
        rep(i, (n-1)/4){
            if(S.at(i)!=S.at((n-1)/2-i-1)){
                cout << "No" << endl;
                return 0;
            }
        }
        
    }
    // for(int i=(n+3)/2-1;i<(n+1)/2+((n-1)/2-1)/2;i++){
    //     if(S.at(i)!=S.at((n+1)/2+n-i-1)){
    //         cout << "No" << endl;
    //         return 0;
    //     }
    // }
    cout << "Yes" << endl;
}