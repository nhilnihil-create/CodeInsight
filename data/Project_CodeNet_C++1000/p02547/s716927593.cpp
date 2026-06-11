	#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010,M=20010;
 typedef pair<int,int> pii;
 int a[N][2];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i][0]>>a[i][1];
    bool flag=false;
    for(int i=3;i<=n;i++)
    {
        if(a[i-2][0]==a[i-2][1] && a[i-1][0]==a[i-1][1] && a[i][0]==a[i][1])
        {
            flag=true;
        }
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}  