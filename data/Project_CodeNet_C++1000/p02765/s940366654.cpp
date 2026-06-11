#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,r;
    cin >> n>>r;
    if(n>=10){
        cout<<r;
    }
    else{
        cout<< r+1000-100*n;
    }
}