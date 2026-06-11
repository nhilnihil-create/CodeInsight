#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt =0 ;
    cin >> n;
    for(int i = 1; i <= n;++i ){
        int p =log10(i);
        if(p%2 == 0){
            ++cnt;
        }
    }    
    cout <<cnt;    
}