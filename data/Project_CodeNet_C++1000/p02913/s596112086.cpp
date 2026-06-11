#include <iostream>
#include <bits/stdc++.h>

using namespace std;
char str[10000];
int n,pi[10000];

int main()
{
    scanf("%d\n%s",&n,str);
    int ans = 0;
    for(int i=0;i<n;++i)
    {
        memset(pi,0,sizeof(pi));
        for(int j=i+1;j<n;++j){
            int k = pi[j-1];
            while(k>0&&str[i+k]!=str[j]) k = pi[i+k-1];
            if(str[i+k]==str[j]) ++k;
            pi[j] = k;
            //cout << k << " " << j<< " " <<str[i] << endl;
            ans = max(ans,min(k,(j-i+1)/2));
        }
    }
    printf("%d\n",ans);
    return 0;
}
