#include<iostream>
using namespace std;
int main(){
    int S=0;
    int s;
    int m;
    int h;
    cin>>S;
    m=(S%3600)/60;
    h=S/3600;
    s=(S%3600)%60;
    cout<<h<<":"<<m<<":"<<s<<endl;

}
