#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin>>x>>y;
    int total=4*x;
    int t1=(total-y);
    if(y>=2*x && y<=4*x && y%2==0)
    {
        t1/=2;
        int t2=x-t1;
        if(t1>=0 && t2>=0)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
    }
    else
    {
        cout<<"No";
    }
  	return 0;
}





