//tanzim bin nasir
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int n,m,t,row_m=0,col_m=0,r,c;
    cin>>n>>m>>t;
   // map<pair<int,int>,int > m;
    map<int,int> row,col;
    map<pair<int,int>,int> man;
    vector<int> rv,cv;
    for(int i=0;i<t;i++)
    {
        int x,y;
        cin>>x>>y;
        man[make_pair(x,y)]=1;
        row[x]++;
        col[y]++;
        if(row[x]>row_m)
        {
            row_m=row[x];
            rv.clear();
        }
        if(row[x]==row_m)
        rv.push_back(x);
        if(col[y]>col_m)
        {
            col_m=col[y];
            cv.clear();
        }
        if(col[y]==col_m)
        cv.push_back(y);
    }
    for(int i=0;i<rv.size();i++)
        for(int j=0;j<cv.size();j++)
    {
        if(man[make_pair(rv[i],cv[j])]!=1)
        {
            cout<<row_m+col_m<<endl;
            return 0;
        }
    }
    cout<<row_m+col_m-1<<endl;
    return 0;
}

