#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    vector<int> q(3);
    rep(i,3) cin>>q[i];
    int choose=2;

    int min=1<<23;
    for (int bit = 0; bit < (1<<3); bit++)
    {
        int cnt=0;
        int buf=0;
        for (int i = 0; i < 3; i++)
        {
            if(bit & (1<<i))
            {
                buf+=q[i];
                cnt++;
            }
        }
        if(cnt!=choose)continue;
        if(min>buf) min=buf;
    }
    cout<<min<<endl;

    return 0;
}