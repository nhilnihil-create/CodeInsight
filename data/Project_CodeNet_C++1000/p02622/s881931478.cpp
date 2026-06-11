
#include <iostream>
#include<string>
typedef long long ll;
using namespace std;

int main()
{
    int c=0;
    string  s1,s2;
    cin>>s1;
    cin>>s2;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i])c++;
    }
    cout<<c;
    return 0;
}
