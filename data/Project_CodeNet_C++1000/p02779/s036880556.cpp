#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int t;
    //cin>>t;
    //while(t--)
    {
        int n ;
        cin>>n;
        vector <int> arr(n);
        for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        set <int> check;
        check.insert(arr.begin(),arr.end());
        if(check.size()==n)
        cout<<"YES\n";
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}