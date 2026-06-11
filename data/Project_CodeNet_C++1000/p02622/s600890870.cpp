#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll c=0,i;
    string ch,sh;
    cin>>ch>>sh;
    for(i=0;i<ch.length();i++){
        if(ch[i]!=sh[i])c++;
    }
    cout<<c<<endl;
}
