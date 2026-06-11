#include<bits/stdc++.h>
using namespace std;
 int main(){
 int A,B,C,D;
 cin>>A>>B>>C>>D;
 int X=(A+D-1)/D;
 int Y=(C+B-1)/B;
 if(X>=Y)
 {
     cout<<"Yes"<<"\n";
 }
 else
 {
     cout<<"No"<<"\n";
 }
 return 0;
 }
 