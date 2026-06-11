#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    
    // 4文字同じの時
    if(s.at(0)==s.at(1)&&s.at(2)==s.at(3)&&(s.at(3)==s.at(1))){
       cout<<"No" <<endl; 
    }
    else{
    // ２：２になっているとき
    if(s.at(0)==s.at(1)&&s.at(2)==s.at(3)){
      cout<<"Yes" <<endl;
    }else if(s.at(0)==s.at(2)&&s.at(1)==s.at(3)){
       cout<<"Yes" <<endl;
    }else if(s.at(0)==s.at(3)&&s.at(1)==s.at(2)){
       cout<<"Yes" <<endl;
    }else{
       cout<<"No" <<endl;
    }
    }
}