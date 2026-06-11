#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int i,a,b;
    cin>>a>>b;
    string stra,strb;
    for(i=0;i<a;i++)
    stra.push_back(b+48);
    for(i=0;i<b;i++)
    strb.push_back(a+48);
    vector<string>str;
    str.push_back(stra);
    str.push_back(strb);
    sort(str.begin(),str.end());
    cout<<str[0]<<endl;
    return 0;
}



