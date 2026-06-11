#include <iostream>
#include <string>
using namespace std;

int main()
{  int cou=0;
    string t;
    string s;
    cin>>s;
    cin>>t;
    for(int i=0;i<s.length();i++){
        if(s[i]!=t[i]){
            cou++;
        }
    }
cout<<cou;
    return 0;
}
