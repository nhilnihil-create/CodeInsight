#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main(){
    string a;
    cin>>a;
    cout<<a;
    int b=a.size();
    if(a.at(b-1)=='s'){
        cout<<"es";
    }else{
        cout<<"s";
    }
}
