#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int fl=1;
    for(char c: s){
        if(c=='7'){
            cout<<"Yes"<<endl;
            fl=0;
            break;
        }
    }
    if(fl)cout<<"No"<<endl;
}
