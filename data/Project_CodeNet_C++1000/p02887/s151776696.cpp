#include <iostream>

using namespace std;

int main()
{
    int n;
    string str;
    cin>>n>>str;
    char x=str[0];
    int num=1;
    for(int i=1;i<n;i++){
        if(x==str[i])
            continue;
        else
        {
            x=str[i];
            num++;
        }
    }
    cout<<num;
    return 0;
}
