#include<bits/stdc++.h> 
#define int long long 
#define pp pair<int,int> 
#define ss second 
#define ff first 
#define pb push_back
#define mod 1000000007
#define mk(arr,n,type)  type *arr=new type[n];
#define sl s1.length();
using namespace std; 
void fastio()
{
  #ifndef ONLINE_JUDGE
  freopen("INPUT.txt","r",stdin);
  freopen("OUTPUT.txt","w",stdout); 
  #endif
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL) ; 
  cout.tie(NULL);
}
signed main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2)
    cout<<"No";
    else
    {
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[i+n/2])
            {
                cout<<"No";
                return 0;
            }
        }
        cout<<"Yes";
    }
    
}