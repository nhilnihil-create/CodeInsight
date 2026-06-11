#include<bits/stdc++.h>
using namespace std;
string l;
int main(){
    cin>>l;
    if(l.back()=='s'){
        l+="es";
    }else
    {
        l+="s";
    }
    cout<<l<<endl;
}