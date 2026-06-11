#include<bits/stdc++.h> 
typedef double ll;
#define pb push_back
#define MP make_pair

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int x=0;
     for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            x=1;
            break;
        }
    }
    if(x==1)
    cout<<"NO";
    else
    cout<<"YES";
   
    

    
     
    
     return 0;
}
