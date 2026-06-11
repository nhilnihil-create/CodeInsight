#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=120;
int a[N];
int main()
{   int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]==a[j] || a[j]==a[k])
                    continue;
                if(a[i]+a[j] > a[k]){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;

}
