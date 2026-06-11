#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    std::string s,t;
    cin>>s>>t;
    if(!t.empty()){
        t.resize(t.size()-1);
    }

    if(s == t){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}
