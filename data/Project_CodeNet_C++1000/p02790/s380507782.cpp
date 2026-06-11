#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iterator>
#include<set>
#include<sstream>
#define rep(i,n) for(i=0;i<n;i++);
#define endl "\n"
#define ll long long
#define N 200050
using namespace std;

int main()
{
   int d,i,m,p=0,q=0,r=0,l;
 int n,x,a,b,c;
    int j;



    cin>>a>>b;
    vector<int> v2(b,a),v1(a,b);
    if(v2[0]>v1[0])
        for(auto &k :v1)
            cout<<k;
    if(v2[0]<v1[0])
                for(auto &k:v2)
                    cout<<k;
    if(a==b)
        for(i=0;i<a;i++)
            cout<<a;



}