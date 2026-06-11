#include<bits/stdc++.h>
using namespace std;
                       ///****   Hasebul Hassan Chowdhury ***////
#define ms(a,v)        memset(a,v,sizeof a)
#define lll            long long
#define FOR(i,a,b)     for(int i=a;i<=b;i++)
#define fast           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Read           freopen("input.txt", "r", stdin)
#define Write          freopen("output.txt", "w", stdout)
#define INF            1000000000


int main()
{
    string s;
    cin>>s;
    int n=s.size();
    string x=s;
    reverse(s.begin(),s.end());
    if(x!=s) { cout<<"No"<<endl; return 0; }
    string now="";
    for(int i=0;i<(n-1)/2;i++) now+=x[i];
    string now2=now;
    reverse(now.begin(),now.end());
    if(now!=now2) { cout<<"No"<<endl; return 0; }
    ///
    string now3="";
    for(int i=((n+3)/2)-1;i<n;i++) now3+=x[i];
    string now4=now3;
    reverse(now3.begin(),now3.end());
    if(now3!=now4) { cout<<"No"<<endl; return 0; }
    cout<<"Yes"<<endl;
}
