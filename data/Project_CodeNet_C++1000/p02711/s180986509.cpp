//
//  main.cpp
//  ABC612A
#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    if (s.find('7')!=string::npos) {
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
