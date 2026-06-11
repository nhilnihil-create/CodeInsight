#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
long long int x,cnt=0,y=100;
cin>>x;
while(y<x){
    y=y+y/100;
    cnt++;
}
cout<<cnt;
    return 0;
}
