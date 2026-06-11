#include <bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    int cnt=0;
    cin >>inp;
    int x =inp.size();
    if(x%2!=0){
        for(int i = 0; i <(x-1)/2; ++i){
            if(inp[i] != inp[x-1-i]){
                ++cnt;
            }
        }
        cout<< cnt;      
    }
    else{
        for(int i = 0; i <x/2; ++i){
            if(inp[i] != inp[x-1-i]){
                ++cnt;
            }
        }
        cout<<cnt;
    }
    
    return 0;
}