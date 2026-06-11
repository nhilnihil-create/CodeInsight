#include<bits/stdc++.h>
using namespace std;
int main(){
string x[3]={"Sunny","Cloudy","Rainy"};
string s;cin>>s;
if(s=="Sunny"||s=="Cloudy"||s=="Rainy"){
for(int i=0;i<3;i++){
    if(s==x[i]&&i!=2)
        {cout<<x[i+1]<<endl;break;}
    else if(i==2)
    {cout<<"Sunny"<<endl;}

}
}
return 0;}
