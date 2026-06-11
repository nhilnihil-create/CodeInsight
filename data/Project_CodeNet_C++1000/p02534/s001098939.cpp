#include <iostream>
#include<cstring>

using namespace std;

int main()
{
    int k;
    cin>>k;
    string name="ACL";
    string s[10];

    
    for (int i=1;i<=k;i++){
        s[i]=s[i-1] + name ;
    }
    cout<<s[k];

    return 0;
}
