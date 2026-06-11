#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long int
#define pb push_back
#define sx 300007
int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;
        if((val%2!=0)&&(i%2!=0))
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
