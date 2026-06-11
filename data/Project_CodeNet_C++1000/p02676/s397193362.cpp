#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=s.size();
    if(n>l)
    {
        cout<<s;
    }
    else
    {
    for(int i=0;i<n;i++)
    {
        cout<<s[i];

    }
    }
    if(n<l)
    {
    cout<<"..."<<endl;
    }



    return 0;

}
