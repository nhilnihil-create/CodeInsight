#include <iostream>
using namespace std;
bool kaibun(string s){
    int l=s.size();
    for(int i=0;i<l/2;++i){
        if(s[i]!=s[l-1-i]) return false;
    }
    return true;
}
int main(void){
    string s;
    cin>>s;
    int l=s.size();
    string s1=s.substr(0,l/2);
    string s2=s.substr((l+1)/2);
    bool b=(kaibun(s) && kaibun(s1));
    cout<<(b && kaibun(s2) ? "Yes":"No")<<endl;
}
