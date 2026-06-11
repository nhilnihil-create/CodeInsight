#include<iostream>
using namespace std;


int main(){

string s;
getline(cin,s);

if(s=="Sunny"){
    cout<<"Cloudy";
}

if(s=="Cloudy"){
    cout<<"Rainy";
}

if(s=="Rainy"){
    cout<<"Sunny";
}

}
