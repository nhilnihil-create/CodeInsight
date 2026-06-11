#include<bits/stdc++.h>
using namespace std;
int main(){

   string s;
   cin>>s;
   int i,c=0;
   int l=s.size();
    for(i=0;i<l-1;i++){
        if(s.at(i)==s.at(i+1)){
            c++;
        }
    }
    if(c==0){
        cout<<"Good"<<endl;
    }
    else{
        cout<<"Bad"<<endl;
    }
}

