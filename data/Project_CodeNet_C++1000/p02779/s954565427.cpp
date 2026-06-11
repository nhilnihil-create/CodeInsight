#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int> a;
    for(int i=0;i<n;i++)
    {
        int r;
        cin>>r;
        a[r]++;
    }
    for(auto p:a) if(p.second>=2)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
}