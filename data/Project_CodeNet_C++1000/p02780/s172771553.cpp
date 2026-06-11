#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n;
    double sum=0;
    cin>>n>>k;
    vector<double> p(n+1); 
    for(int i=1;i<=n;i++){
        double a;
        cin>>a;
        a=(a+1)/2;
        sum+=a;
        p[i]=sum;
    }
    double ans=0;
    for(int i=0;i<n-k+1;i++)
    {
        ans=max(ans,p[i+k]-p[i]);
    }
    printf("%.10f",ans);
    return 0;
}