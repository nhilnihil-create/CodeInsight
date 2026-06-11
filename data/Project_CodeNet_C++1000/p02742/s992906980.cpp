#include <bits/stdc++.h>
using namespace std;
int i,j,k,count1=0,count2=0;

int main(void){
    long long int h,w;
    cin>>h>>w;
    if(w==1||h==1)cout<<1<<endl;
    else if(h*w%2==0)cout<<h*w/2<<endl;
    else cout<<(h*w+1)/2<<endl;
}