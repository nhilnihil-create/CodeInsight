#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,l[1000000],i,j,k,c=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> l[i];
    }
    sort(l,l+n,greater<int>());
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(l[i]<l[j]+l[k] && l[i]!=l[j] && l[i]!=l[k] && l[j] != l[k])
                {
                    c++;
                }
            }
        }
    }
    cout << c << endl;
    return 0;

}
