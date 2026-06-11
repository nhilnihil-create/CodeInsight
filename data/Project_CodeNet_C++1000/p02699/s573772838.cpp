#include<bits/stdc++.h>
using namespace std;
int S,W;

int main(){
    cin >> S >> W;
    if(W>S){
        cout <<"unsafe";
    }
    else if(W==S){
        cout <<"unsafe";
    }
    else{
        cout <<"safe";
    }
}