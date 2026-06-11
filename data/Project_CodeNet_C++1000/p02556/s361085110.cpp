#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int x[maxn],y[maxn];
int main(){ 
     int n;
     scanf("%d",&n);
     for(int i=1;i<=n;++i){ 
        int a,b;
        scanf("%d%d",&a,&b);
        x[i]=a+b;y[i]=a-b;
     }
     sort(x+1,x+1+n);
     sort(y+1,y+1+n);
     cout<<max(y[n]-y[1],x[n]-x[1])<<endl;
}
