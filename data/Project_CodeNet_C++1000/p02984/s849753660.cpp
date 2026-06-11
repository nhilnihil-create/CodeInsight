#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

#define mod 2019
#define INF 2<<30

int x[100010];

int main(void){
    // Your code here!
    ll n;
    cin >> n;
    
    for(int i=0;i<n;i++)cin>>x[i];
    
    int x1=x[0];
    for(int i=1;i<n;i+=2)
    {
        x1 += -x[i]+x[i+1];
    }
    
    int a=x1/2;
    cout << a*2;
    for(int i=0;i<n-1;i++)
    {
        int ans=x[i]-a;
        a=ans;
        cout<<" "<<ans*2;
        
    }
}

