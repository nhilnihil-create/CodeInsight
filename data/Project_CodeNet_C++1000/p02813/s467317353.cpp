#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=10;
int a[N];
int b[N];
int c[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0;i<n;i++)scanf("%d",b+i);
    bool q=1;    int x,y;
    for(int i=0;i<n;i++)c[i]=i+1;

    for(int i=0;i<n;i++){
        if(a[i]!=c[i])
            q=0;
    }
    if(q)
        x=1;
    q=1;
    for(int i=0;i<n;i++){
        if(b[i]!=c[i])
            q=0;
    }
    if(q)
        y=1;
    int cnt=1;
    while(next_permutation(c,c+n)){
            cnt++;
    bool q=1;
        for(int i=0;i<n;i++){
            if(a[i]!=c[i])
                q=0;}
        if(q)
            x=cnt;
        q=1;
        for(int i=0;i<n;i++){
            if(b[i]!=c[i])
                q=0;
        }
        if(q)
            y=cnt;
    }
    cout<<abs(x-y);
}
