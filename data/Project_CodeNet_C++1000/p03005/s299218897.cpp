#include <bits/stdc++.h>
using namespace std;

typedef vector<int>  vi;
typedef set<char> setchar;
typedef set<int> sett;
typedef deque <int> dq;
typedef long long ll;
#define vec(a)  a.begin(),a.end()
#define pb     push_back
#define pf     push_front
#define mem(a,b) memset(a,b,sizeof(a));
#define inI(a)  scanf("%d",&a);
#define inL(a)  scanf("%lld",&a);
#define uff ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
//int fx[]={+0,-1,-1,-1,+0,+1,+1,+1};
//int fy[]={-1,-1,+0,+1,+1,+1,+0,-1};
int fx[]= {0,-1,0,+1};
int fy[]= {-1,0,+1,0};



int main()
{
     uff
    //freopen("input.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    if(k==1)
        cout<<"0"<<endl;
    else
    {
        cout<<(n-k)<<endl;
    }



    return 0;

}





