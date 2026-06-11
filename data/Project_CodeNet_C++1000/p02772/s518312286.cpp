#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)
    {
        int b;
        cin>>b;
        if(b%2==0)
        {
            if(b%3!=0&&b%5!=0)
            {
                cout<<"DENIED";
                return 0;
            }
        }
    }
    cout<<"APPROVED";
}