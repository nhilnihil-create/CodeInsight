#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
typedef unsigned long long int ull;
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    ull n,a[100001],p=1;
    cin>>n;
    for (ull i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]==0){
            cout<<0<<endl;
            return 0;
        }
        
    }
    for (ull i = 0; i < n; i++)
    {
        if(a[i]<=1000000000000000000/p){
            p*=a[i];
        }else{
             cout<<-1<<endl;
            return 0;
        }
      
    }
    
    
    cout<<p<<endl;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	

   return 0;
}
