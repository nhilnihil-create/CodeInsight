#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include<algorithm>
#include <set>
#include <stdlib.h>

using namespace std;

int main()
{
    int n,q,r=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>q;
        if(q%2!=0 &&i%2!=0)
            r++;
    }
    cout<<r;

    return 0;
}
