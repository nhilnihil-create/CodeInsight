#include <bits/stdc++.h>
using namespace std;
int main(){
vector<vector<int>>A(3,vector<int>(3));
vector<vector<bool>>B(3,vector<bool>(3));
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        cin>>A.at(i).at(j);
    }
}
int N;
cin>>N;
vector<int>C(N);
for(int i=0; i<N; i++){
    cin>>C.at(i);
    for(int j=0; j<3; j++){
        for(int k=0; k<3; k++){
            if(C.at(i)==A.at(j).at(k)){
                B.at(j).at(k)=true;
            }
        }
    }
}
bool t=false;
if(B.at(0).at(0)==true&&B.at(0).at(1)==true&&B.at(0).at(2)==true){
    t=true;
}
if(B.at(1).at(0)==true&&B.at(1).at(1)==true&&B.at(1).at(2)==true){
    t=true;
}
if(B.at(2).at(0)==true&&B.at(2).at(1)==true&&B.at(2).at(2)==true){
    t=true;
}
if(B.at(0).at(0)==true&&B.at(1).at(0)==true&&B.at(2).at(0)==true){
    t=true;
}
if(B.at(0).at(1)==true&&B.at(1).at(1)==true&&B.at(2).at(1)==true){
    t=true;
}
if(B.at(0).at(2)==true&&B.at(1).at(2)==true&&B.at(2).at(2)==true){
    t=true;
}
if(B.at(0).at(0)==true&&B.at(1).at(1)==true&&B.at(2).at(2)==true){
    t=true;
}
if(B.at(0).at(2)==true&&B.at(1).at(1)==true&&B.at(2).at(0)==true){
    t=true;
}
if(t==true){
    cout<<"Yes"<<endl;
}
else
cout<<"No"<<endl;
}
