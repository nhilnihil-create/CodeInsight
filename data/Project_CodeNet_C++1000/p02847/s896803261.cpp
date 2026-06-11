#include<bits/stdc++.h>
using namespace std;
#define sx 200007
int main()
{
    map<string,int> m;
    m["SUN"]=7;
    m["MON"]=6;
    m["TUE"]=5;
    m["WED"]=4;
    m["THU"]=3;
    m["FRI"]=2;
    m["SAT"]=1;
    string s;
    cin>>s;
    cout<<m[s]<<endl;
    return 0;
}
