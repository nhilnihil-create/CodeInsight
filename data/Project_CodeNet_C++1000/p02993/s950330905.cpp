#include <bits/stdc++.h>
using namespace std;
int main(){
 string S;
 cin>>S;
bool a=false;
int count=0;
 if(S.at(0)==S.at(1)){
 a=true;
 }
 else if(S.at(1)==S.at(2)){
     a=true;
 }
 else if(S.at(2)==S.at(3)){
     a=true;
 }
 if(a==true){
     cout<<"Bad"<<endl;
 }
 else
 cout<<"Good"<<endl;
}
