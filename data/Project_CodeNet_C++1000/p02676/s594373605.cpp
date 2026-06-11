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
    int n,k;
    string s;
    cin>>k>>s;
    n=SZ(s);
    if(n<=k){
        cout<<s;
        return 0;
    }
    cout<<s.substr(0,k)+"...";
    

    
	

   return 0;
}
