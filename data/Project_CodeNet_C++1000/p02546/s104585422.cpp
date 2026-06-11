#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ss;
    cin>>ss;
    if(ss.back()=='s')
        ss+="es";
    else
        ss+='s';
    cout<<ss<<endl;

}
