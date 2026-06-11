#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

#define T int t, q=0; scanf("%d", &t); while(q++<t)
#define ll long long
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll y,a,b,c=0,sum=0,ans,total,cnt,n,m,k,p,kase,i;
string s1,s2;
#define N 100001
#define MX 1000000001



int main()
{
    cin>>n>>m;
    int a[n];
    c=0,sum=0;
    for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
    }
    float z=4*m;
   float x=(1/z)*sum;
    for(int i=0;i<n;i++){
        if(a[i]>=x)c++;

    }
    if(c>=m){
            cout<<"Yes"<<endl;
        }
    else cout<<"No";



    return 0;
}
// Happy Coding  (:
