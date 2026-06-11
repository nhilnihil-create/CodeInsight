#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6+10 , OO = 0x3f3f3f3f ;
const int mod = 1e9 + 7;
 
#define clr(arr,val) memset(arr , val , sizeof (arr))
#define loop(i,n) for(int i = 0;i < int(n);i++)
#define rloop(i,n) for(int i = int(n)-1;i >= 0;i--)
#define xloop(i,a,b) for(int i = int(a);i <= int(b);i++)
#define range(vec) for(auto &x : vec) cin >> x;
#define ALL(v) ((v).begin()) , ((v).end())
#define SZ(v)  ((int)((v).size()))
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

int a,  b;

int main()
{
   // startTime = (double)clock();
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
        //freopen("out.in", "w", stdout);
    #endif
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    scanf("%d %d",  &a , &b);
    printf("%d\n" , a * b);

    return 0;
}