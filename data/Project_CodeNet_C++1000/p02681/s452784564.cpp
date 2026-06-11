#include <iostream>
#include <string>

using namespace std;

int main(){
    string S,T;
    cin>>S>>T;
    if(S==T.substr(0,S.size()))cout<<"Yes\n";
    else cout<<"No\n";
}