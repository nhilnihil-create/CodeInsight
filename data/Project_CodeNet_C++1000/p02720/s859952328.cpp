#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
queue <long long >q;
int main() {
    int k;
    cin>>k;
    if(k<=9)
    {
        cout<<k<<endl;
        return 0;
    }
    k-=9;
    for(int i=1;i<=9;i++) q.push(i);
    while(k)
    {
        long long t=q.front();
        if(t%10)
        {
            k--;
            if(k==0)
            {
                printf("%lld\n",t*10+(t%10)-1);
                break;
            }
            q.push(t*10+(t%10)-1);
        }
        k--;
        if(k==0)
        {
            printf("%lld\n",t*10+(t%10));
            break;
        }
        q.push(t*10+(t%10));
        if(t%10<9) {
            k--;
            if (k == 0) {
                printf("%lld\n", t * 10 + (t % 10)+1);
                break;
            }
            q.push(t * 10 + (t % 10)+1);
        }
        q.pop();
    }
    return 0;
}
