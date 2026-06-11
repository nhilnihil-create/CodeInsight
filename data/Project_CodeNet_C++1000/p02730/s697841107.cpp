#include <bits/stdc++.h>
using namespace std;
int main(){
string S;
cin>>S;
int X=S.size();
vector<char>A((X-1)/2);
vector<char>B((X-1)/2);
for(int i=0; i<(X-1)/2; i++){
    A.at(i)=S.at(i);
}
for(int i=0; i<(X-1)/2; i++){
    B.at(i)=S.at(i+(X+1)/2);
}
bool a=true;
for(int i=0; i<(X-1)/2; i++){
    if(A.at(i)!=B.at(i)){
        a=false;
    }
}
if(a==true){
    if((X-1)/2%2==0){
      for(int i=0; i<(X-1)/2/2; i++){
        if(S.at(i)==S.at((X-1)/2-i-1)){
        }
        else{
          cout<<"No"<<endl;
        	break;
      }
      }
      cout<<"Yes"<<endl;
    }
      else{
        for(int i=0; i<((X-1)/2-1)/2; i++){
          if(S.at(i)==S.at((X-1)/2-i-1)){
          }
          else{
            cout<<"No"<<endl;
          break;
        }
      }   
                  cout<<"Yes"<<endl;
}
}
else
cout<<"No"<<endl;
}
