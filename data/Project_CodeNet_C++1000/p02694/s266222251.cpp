#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t x,y=100;
cin>>x;
int64_t count=0;
while(y<x){
  y+=y/100;
  count++;
}
cout<<count<<endl;
}
