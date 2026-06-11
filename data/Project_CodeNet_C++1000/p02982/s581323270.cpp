#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

#define mod 2019
#define INF 2<<30

int x[10][10];

int main(void){
    // Your code here!
    ll n,d;
    cin >> n >> d;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<d;j++)cin>>x[i][j];
    }
    
    int ans=0;
    
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
    {
        int a=0;
        for(int k=0;k<d;k++)
        {
            int b=x[i][k]-x[j][k];
            a+=b*b;
        }
        
        float ip=0.0f;
        float d=sqrt(a);
        if(modf(d, &ip)==0)ans++;
    }
    
    cout<<ans;
}

