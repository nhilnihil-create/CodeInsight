#include<bits/stdc++.h>
using namespace std;
const int N = 110;
#define x first
#define y second
typedef pair<int,int> pii;
pii g[N];
int main()
{
    
    int n;
    cin>>n;
    int cnt=0;
    bool st=false;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==b) cnt++;
        else cnt=0;
        if(cnt>=3)
        {
            st=true;
            break;
        }
    }
    
    if(st) puts("Yes");
    else puts("No");
     
 
    
}