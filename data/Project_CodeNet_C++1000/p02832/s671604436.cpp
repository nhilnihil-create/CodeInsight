#include<iostream>
#include<vector>
#define lli long long int
#include<climits>
#include<unordered_map>
#include<algorithm>
#include<bitset>
#include<map>
#define pb push_back
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)  cin>>arr[i];
    int k =1;
    int b =0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==k)
        {
            k++;
        }
        else b++;
    }
    
    if(b!=n) cout<<b<<endl;
    else cout<<-1<<endl;
}

