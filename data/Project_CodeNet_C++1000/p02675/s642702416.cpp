#include<bits/stdc++.h>
using namespace std;
int main(){
 string S;
 cin>>S;
 int a=S.size();
 if(S.at(a-1)=='3'){
   cout<<"bon"<<endl;
 }
 else if(S.at(a-1)=='0'||S.at(a-1)=='1'||S.at(a-1)=='6'||
 S.at(a-1)=='8'){
  cout<<"pon"<<endl;
 }
 else{
  cout<<"hon"<<endl;
 }
}

