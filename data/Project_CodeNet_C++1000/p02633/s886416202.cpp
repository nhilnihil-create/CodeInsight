#include<bits/stdc++.h>

using namespace std;


int main(){
    int x;cin>>x;
    int id;
    for(int i=1;;++i){
        if(i*360%x==0){
            id=i;
            break;
        }
    }
    cout<<id*360/x;

    return 0;
}
