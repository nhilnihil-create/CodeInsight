#include <bits/stdc++.h>
using namespace std;
int main(){
int N,M;
cin>>N>>M;
vector<int>s(M);
vector<int>c(M);
vector<int>answer(N);
vector<bool>h(N);
bool a=false;
if(M==0){
    if(N==1){
        cout<<0<<endl;
    }
    else{
    cout<<1;
    for(int i=0; i<N-1; i++){
        cout<<0;
    }
    cout<<""<<endl;
}
}
else{
    bool z=false;
for(int i=0; i<M; i++)
{
    cin>>s.at(i);
    cin>>c.at(i);
    if(c.at(i)!=0){
        z=true;
    }
    if(h.at(s.at(i)-1)==true&&answer.at(s.at(i)-1)!=c.at(i)&&c.at(i)!=0){
        a=true;
    }
  else if(c.at(i)==0&&s.at(i)==1){
    a=true;
  }
    answer.at(s.at(i)-1)=c.at(i);
    h.at(s.at(i)-1)=true;
}
if(z==true){
if(a==false){
if(answer.at(0)==0){
    answer.at(0)=1;
}
for(int i=0; i<N; i++){
cout<<answer.at(i);
}
cout<<""<<endl;
}
else
{
    cout<<-1<<endl;
}
}
else
{
    bool g=false;
    for(int i=0; i<M; i++){
        if(s.at(i)==1){
        }
        else
        g=true;
    }
    if(g==true||N==1){
   if(N==1){
        cout<<0<<endl;
    }
    else{
    cout<<1;
    for(int i=0; i<N-1; i++){
        cout<<0;
    }
    cout<<""<<endl;
    }
}
else
cout<<-1<<endl; 
}

}
}
