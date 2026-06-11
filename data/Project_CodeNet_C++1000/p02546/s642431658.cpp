#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;
    int l=s.length();
    if(s.at(l-1)=='s'){
        cout<<s+"es"<<"\n";
    }else{
        cout<<s+'s'<<"\n";
    }
}