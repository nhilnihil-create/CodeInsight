#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int heal[300000];

multiset<int> s;

int main()
{
    int n;scanf("%d",&n);
    int num=1;
    while (n--) num*=2;

    for (int i=1;i<=num;i++)
        scanf("%d",&heal[i]);

    for (int i=1;i<=num;i++)
        s.insert(-heal[i]);
    int tmp=1;
    heal[1]=-(*s.begin());
    s.erase(s.begin());

    for (int j=1;j<=num/2;j*=2)
    {
        int _tmp=tmp;
        for (int i=1;i<=_tmp;i++)
        {
            multiset<int>:: iterator it;
            it = s.upper_bound(-heal[i]);
            //printf("%d %d\n",heal[i],-*it);
            if (it!=s.end())
            {
                heal[++tmp]=-*it;
                s.erase(it);
            }
        }
        if (tmp!=j*2){
            printf("No\n");return 0;
        }
    }

    printf("Yes\n");

}
