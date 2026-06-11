#include<bits/stdc++.h>
using namespace std;
int main(){

int x,y,r,count =0;
cin>>x>>y;
for(int i=0;i<10000;i++){
    if(x>0){
        r = x-y;
        x=r;
        count++;


    }



}
cout<<count;





}
