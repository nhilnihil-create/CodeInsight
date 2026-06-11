#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bits/stdc++.h>
#define INF 1555889
#define ll long long
#define ms(x, a) memset(x, a, sizeof(x))
#define endl "\n"
#define M(a, b) (a + b) / 2
#define L(x) 2 * x
#define R(x) 2 * x + 1
#define pb(a) push_back(a)
#define MOD 1000000000
#define f(x,a,b) for(ll x=a;x<=b;x++)
using namespace std;
typedef pair<ll, ll> ii;
typedef pair<ll, vector<ll > > iv;
typedef pair<ll, ii> iii;
ll Move[8][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }, { 1, 1 }, { -1, 1 }, { 1, -1 }, { -1, -1 } };
void sync()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
/*
    comment??
    nothing at all
    ah oui bien sure
    fuck you bitch
    fils de pute
*/
char origine[105][105],cop[105][105];
int n;
void _new(){
    ms(origine,'#');
    ms(cop,'#');
    return ;
}
/*
           ^
           |
   ------------------
   |global variables|
   ------------------
*/
int  main()
{
    //ofstream cout("tst1.txt",ofstream::out);
    //ifstream cin("tst.txt",ifstream::in);
    int n;
    cin>>n;
    int a[n+5],m[n+5],b[n+5];
    ms(m,0);
    ms(b,0);
    f(i,1,n){
        cin>>a[i];
    }
    bool impossible=false;
    vector<int>v;
    for(int i=n;i>=1;i--){
        if(a[i]==m[i])continue;
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                m[j]=(m[j]+1)%2;
                if(i/j!=j)
                    m[i/j]=(m[i/j]+1)%2;
            }
        }
        b[i]=(b[i]+1)%2;
        if(b[i]==1)v.pb(i);

    }
    cout<<v.size()<<endl;
    for(auto y:v)cout<<y<<" ";



}
/*
4 3
4 4 4 4
1 2
2 3
3 4
4
1 2 3 4
0 0*/
