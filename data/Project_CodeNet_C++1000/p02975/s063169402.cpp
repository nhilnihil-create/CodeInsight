#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int64_t a[n];
    for(int x = 0; x < n; x++)
    {
        cin>>a[x];
    }
    int c = 0;
    //sort(a, a+n);
    for(int x = 0; x < n; x++)
    {
        c = c^a[x];
        //cout<<c<<endl;
    }
    if(c == 0)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
