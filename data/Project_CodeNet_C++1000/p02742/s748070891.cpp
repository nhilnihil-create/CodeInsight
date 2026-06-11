#include<bits/stdc++.h>
using namespace std;
int main(){
    long long h,w;cin>>h>>w;
    if(h==1 || w==1){cout<<1;return 0;}
    if(h%2==0 || w%2==0)cout<<(h*w)/2;
    else cout<<(h*w)/2+1;
}