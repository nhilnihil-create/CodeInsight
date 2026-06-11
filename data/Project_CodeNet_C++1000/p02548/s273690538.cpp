#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1;

int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*i<n;j++){
            ans++;
        }
    }
    printf("%d",ans);

}
