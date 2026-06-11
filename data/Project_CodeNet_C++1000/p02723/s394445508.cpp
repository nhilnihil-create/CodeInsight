#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;

    for(int i = 0;i<s.length();i++){
        if((s[i+2] == s[i+3]) &&(s[i+4] == s[i+5])){
            cout<<"Yes";
            break;
        }
        else{
            cout<<"No";
            return 0;
        }
    }
}
