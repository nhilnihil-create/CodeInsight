  //Name : Rupa Dey
  //Date : 28 august 2020
//joi sri gour hori gobindo...
//gobindo ja hobe vlor jonnoi hobe..
#include<bits/stdc++.h>
#define ll long long
#define d double
#define ld long double
#define vi vector<int>
#define vul vector<ull>
#define vl vector<ll>
#define pb push_back
#define si set<int>
#define sl set<ll>
#define yes cout<<"YES\n"<<endl
#define no cout<<"NO\n"<<endl
#define ys cout<<"Yes\n"<<endl
#define n cout<<"No\n"<<endl
#define test cin>>t; while(t--)
#define for(i,a,n) for(i=a;i<n;i++)
#define mp make_pair
#define ft first
#define sc second
#define gap " ";
#define MAX 9999999
#define MOD 1000000007
#define nd endl
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,y,i,j,total=0;
    double select =0; //ceil return floating point
    cin>>x>>y;
    int a[x];
    for(i,0,x)
    {
        cin>>a[i];
        total+=a[i];
    }
    select = (ceil(total))/(4*y);
      //cout<<select;
    sort(a,a+x,greater<int>());

    for(j,0,y)
    {
        if(a[j]<select){   //less than select ..
            n;
           return 0;}
           //j--;
    }
    ys;
}
//hare krishna...
//hey gobindo kripa koro......
//only gobindo exists..^..
