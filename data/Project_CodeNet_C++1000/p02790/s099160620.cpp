#include<bits/stdc++.h>
using namespace std;
int main(){
int   x,y;
cin>>x>>y;
stringstream ss,dd;
ss<<x;
dd<<y;
string q,first,w,second;
ss>>q;
dd>>w;

for(int i=0;i<y;i++){
     first = first+q;
}

for(int i=0;i<x;i++){
second = second+w;
}
if(x<y){
    cout<<first;
}
else if(x>y){
    cout<<second;
}
else{
    cout<<second;
}
}
