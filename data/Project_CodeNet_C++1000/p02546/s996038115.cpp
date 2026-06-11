#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    string s ;
    cin>>s;
    if (s[s.size()-1]=='s'){
        s+="es";
        cout<<s<<endl;
    }
    else {s+="s";
        cout<<s<<endl;
        
    }
    return 0;
}
