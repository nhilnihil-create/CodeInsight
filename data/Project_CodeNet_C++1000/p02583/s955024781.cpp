  //Name : Rupa Dey
  //Date : 24 August 2020
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
//#define for(i,a,n) for(i=a;i<n;i++)
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
    int x,i,j,k,cnt=0,a;
    cin>>x;
    vi vec;
    vec.clear();
    for(i=0;i<x;i++) {
            cin>>a;
            vec.pb(a);}

    sort (vec.begin(),vec.end());
   // for(i=0;i<x;i++) cout<<vec[i];
   //fully dull headed.....

    for(i=0;i<vec.size();i++)
    {
        for(j=i+1;j<vec.size();j++)
        {
            for(k=j+1;k<vec.size();k++)
            {
                if(((vec[i]+vec[j])>vec[k])&&(vec[i]!=vec[j]) && (vec[j]!=vec[k]) && (vec[k]!=vec[i]))
                {

                        cnt++;
                }
            }
        }
    }

    cout<<cnt<<nd;



}
//hare krishna...
//hey gobindo kripa koro......
//only gobindo exists..^..
