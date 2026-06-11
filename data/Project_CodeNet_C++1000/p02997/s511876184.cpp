#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,k;
vector<pair<int,int>> ed;

void pt()
{
    printf("%d\n",(int)ed.size());
    for(int i=0;i<ed.size();++i)
        printf("%d %d\n",ed[i].first+1,ed[i].second+1);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;++i) ed.push_back(pair<int,int>(0,i));
    if(n<3){
        if(k!=0){
            printf("-1\n");return 0;
        }
    }else{
        int nk = (n-1)*(n-2)/2;
        if(nk<k){
            printf("-1\n");return 0;
        }
        if(nk>k)
            {
                for(int i=1;i<n&&nk>k;++i)
                {
                    for(int j=i+1;j<n&&nk>k;++j)
                    {
                        ed.push_back(pair<int,int>(i,j));--nk;
                    }
                }
            }
    }
    pt();
    return 0;
}
