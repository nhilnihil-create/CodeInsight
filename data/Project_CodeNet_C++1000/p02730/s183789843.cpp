#include <bits/stdc++.h>
using namespace std;
bool ispalin(string inp){
    bool ans =true;
    int x = inp.size();
    if (x%2==0){
        for(auto i =0; i< x/2; ++i){
            if(inp[i]!=inp[x-1-i]){
                ans=false;
            }
        }
    }
    else{
        for(auto i =0; i< (x-1)/2; ++i){
            if(inp[i]!=inp[x-1-i]){
                ans=false;
            }
        }
    }
    return ans;
}
int main(){
    string inp, inp1 = "", inp2 = "";
    cin >>inp;
    int x =inp.size();
    for(int i =0; i< (x-1)/2; ++i){
        inp1 += inp[i];
    }
    for(int i =(x+3)/2-1; i< x; ++i){
        inp2 += inp[i];
    }
    if(ispalin(inp)&&ispalin(inp1)&&ispalin(inp2)){
        cout << "Yes";
    }
    else{
        cout <<"No";
    }
}