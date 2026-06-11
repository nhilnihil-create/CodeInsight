#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <algorithm>
#define brijesh ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pb push_back
#define popb pop_back
#define l1 long long
#define vi vector<int>
#define vl vector<l1>
#define vs vector<string>
using namespace std;
int main() {
    brijesh;
    int a,b,n,temp;
    cin>>n;
    vi v1,v2,v3;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v1.pb(temp);
        v3.pb(temp);
    }
    sort(v3.begin(),v3.end());
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v2.pb(temp);
    }
    int count=1,flag=0;
    do{
        if(v3==v1){
            a=count;
            flag++;
        }
        if(v3==v2) {
            b=count;
            flag++;
        }
        count++;
        if(flag==2)
            break;
    }while(next_permutation(v3.begin(),v3.end()));
    cout<<abs(a-b);
}