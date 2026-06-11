#include<iostream>
using namespace std;
int main()
{
    int sum=0;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();i++)
        if(a[i]==b[i])sum++;
    cout<<a.size()-sum<<endl;
    return 0;
}
