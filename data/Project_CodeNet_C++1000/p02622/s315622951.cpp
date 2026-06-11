//Hariom_Pandey

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str, str2;
    cin>>str>>str2;
    int cnt=0;
    for(int i=0; i<str.size(); i++){
        
        if(str[i]!=str2[i]) cnt++;
  
    }
    cout<<cnt;
}
