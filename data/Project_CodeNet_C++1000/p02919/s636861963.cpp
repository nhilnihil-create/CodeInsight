#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MODADD(ADD_X,ADD_Y)  (ADD_X+ADD_Y)%MOD;
#define MODSUB(SUB_X,SUB_Y)  (SUB_X-SUB_Y)+MOD)%MOD;
#define MODMUL(MUL_X,MUL_Y)  (MUL_X*MUL_Y)%MOD;
#define LCM(LCM_X,LCM_Y) (LCM_X*LCM_Y)/__gcd(LCM_X,LCM_Y);
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
int dx[]= {1,0,-1,0,1,-1,1,-1};
int dy[]= {0,1,0,-1,1,-1,-1,1};
ll arr[MAX],freq[MAX],pos[MAX],n;
int lg[MAX], rmq[20][MAX];
void Sparse_Table_Pre_Process(int n)
{
    for(int i=0; i<n; i++)
        rmq[0][i]=arr[i];
    for(int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    for(int i = 1; i <= lg[n]; i++)
        for(int j = 0; j < n - (1 << i) + 1; j++)
            rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
}
int RMQ(int x,int y)
{
    return max(rmq[lg[y - x + 1]][x], rmq[lg[y - x + 1]][y - (1 << lg[y - x + 1]) + 1]);
}
int find_greater_L(int l,int r,int i)
{
    int f=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        int cur=RMQ(mid,i-1);
        if(cur>arr[i])
        {
            f=cur;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return f;
}
int find_greater_R(int l,int r,int i)
{
    int f=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        int cur=RMQ(i+1,mid);
        if(cur>arr[i])
        {
            f=cur;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return f;
}
ll l_side(int i)
{
    int a=find_greater_L(0,i-1,i);
    if(a)
    {
        int x=1,y=0,z=pos[a];
        int l=0,r=pos[a]-1;
        while(l<=r){
            int mid=(l+r)>>1;
            int cur=RMQ(mid,pos[a]-1);
            if(cur>arr[i]){
                l=mid+1;
            }
            else{
                z=mid;
                r=mid-1;
            }
        }
        x+=pos[a]-z;
        int b=find_greater_R(i+1,n-1,i);
        if(b)
        {
            y=pos[b]-i-1;
        }
        else
            y=(n-1)-i;
        int ans=x+x*y;
        return ans;
    }
    return 0;
}
ll r_side(int i)
{
    int a=find_greater_R(i+1,n-1,i);
    if(a)
    {
        int x=1,y=0,z=pos[a];
        int l=pos[a]+1,r=n-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int cur=RMQ(pos[a]+1,mid);
            if(cur>arr[i])
            {
                r=mid-1;
            }
            else
            {
                z=mid;
                l=mid+1;
            }
        }
        x+=z-pos[a];
        int b=find_greater_L(0,i-1,i);
        if(b)
            y=i-pos[b]-1;
        else
            y=i;
        int ans=x+x*y;
        return ans;
    }
    return 0;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll sum=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        pos[arr[i]]=i;
    }
    Sparse_Table_Pre_Process(n);
    for(int i=0; i<n; i++)
    {
        freq[arr[i]]+=l_side(i);
        freq[arr[i]]+=r_side(i);
        // cout<<arr[i]<<" "<<freq[arr[i]]<<endl;
    }
    for(ll i=1; i<=n; i++)
    {
        sum+=(freq[i]*i);
       // cout<<i<<" "<<freq[i]<<endl;
    }
    cout<<sum<<endl;


    return 0;
}
