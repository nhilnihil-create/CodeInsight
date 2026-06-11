#include <bits/stdc++.h>
//#include <unordered_map>
#define M ((ll)1e12)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi acos(-1)
typedef long long ll;
using namespace std;
set<int> s;set<pair<int,int>> s1;int n,m;int visited[100001]={0};

void solve(){
       int x,y;
       int s=0;
       cin>>x>>y;
       if(x==1&&y==1)
       s=400000;
       if(x==1)
       s+=300000;
       else if(x==2)
       s+=200000;
       else if(x==3)
       s+=100000;
       if(y==1)
       s+=300000;
       else if(y==2)
       s+=200000;
       else if(y==3)
       s+=100000;
       cout<<s<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}