#include<iostream>
#include<string.h>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define inf 0x3f3f3f3f
#define N




int main()
{
	std::ios::sync_with_stdio(false);
    long long k,minn;
    while(cin>>minn>>k)
    {
        if(minn%k)
        {
            minn=minn%k;
        while(abs(minn-k)<minn)
        {
            minn=abs(minn-k);
        }
        }
        else
            minn=0;
        cout<<minn<<endl;
    }
	return 0;
}
