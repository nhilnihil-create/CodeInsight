#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void){
    // Your code here!
    int h,w;
    cin>>h>>w;
    ll sum = 0;
    if(h==1 || w==1){ cout<<1<<endl;
    return 0;}
    for(int i=0;i<h;i++){
        if(i%2==0) sum += (w+1)/2;
        else sum += w/2;
    }
    cout<<sum<<endl;
}
