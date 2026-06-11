#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin >>S;
    int N =S.size();
    int ans=0;
    bool one =false;
    
    int i=0;
    while(i<N){
        if(i==N-2 && S.at(i)==S.at(i+1)){
            ans++;
            break;
        }
        if(one &&S.at(i)==S.at(i-1)){
            ans++;
            i+=2;
            one =false;
        }
        else{
            ans++;
            i++;
            one=true;
        }
    }
    cout <<ans<<endl;

}