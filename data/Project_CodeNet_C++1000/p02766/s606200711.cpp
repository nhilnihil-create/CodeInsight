#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;

    if(n==10)
    {
        string a = to_string(n);
        cout<<a.size();
    }

    else
    {
       vector<int>b;
       while(n!=0)
       {
           n=n/k;
           b.push_back(n%k);
       }

       cout<<b.size()<<endl;
    }

    exit(0);
}
