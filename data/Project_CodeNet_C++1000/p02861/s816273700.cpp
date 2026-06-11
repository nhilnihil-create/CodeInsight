#include<bits/stdc++.h>
#define PB push_back
#define FO(i,a,b) for (int i = a; i <= b; i++)
#define FOb(i,a,b) for(int i=b;i>=a;i--)
#define vi vector<int>
#define vulli vector<unsigned long long int>
using namespace std;
typedef unsigned long long int ulli;
int fact(int n){
    int f = 1;
    FO(i,2,n)
        f *= i;
    return f;
}
double dist(int i,int j,vi x ,vi y){
    double distance = ( (x[i] - x[j]) * (x[i] - x[j]) ) + ( (y[i] - y[j]) * (y[i] - y[j]) );
    return sqrt(distance);
}
void solve()
{   
    int n,k;
    double num = 0;
    cin >> n;
    k = n;
    vector<int> x(n+1),y(n+1);
    x[0] = y[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            num += dist(i,j,x,y) * 2;
    cout << fixed << setprecision(10) << num /n ;
}                                             
int main()
{
    std::ios_base::sync_with_stdio(false);
    ulli t=1;
   // cin>>t;   
    while(t--){ solve(); cout<<"\n"; }
    return 0;
}
