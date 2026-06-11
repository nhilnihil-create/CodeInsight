#include <bits/stdc++.h>
using namespace std;

int main ()
{
string S;
cin>>S;
if(S=="Sunny"||S=="Cloudy"||S=="Rainy"){
if(S=="Sunny"){
    cout<<"Cloudy";
}
if(S=="Cloudy"){
    cout<<"Rainy";
}
if(S=="Rainy"){
    cout<<"Sunny";
}
}
return 0;
}