#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    long long sum=0,m=0;
    cin >> n >>k;
    int x=abs(n-k);
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
        m+=arr[i];
    
   // cout << m;
        
    }
    if (n==k||k>n)
    cout << 0<< "\n";
    else if (k==0)
    cout << m <<"\n";
    else
    {
    sort(arr,arr+n);
    for(int i=n-1;i>=x;i--)
    {
        //cout << i << " " <<arr[i] <<"\n";
        sum+=arr[i];
    }
   cout <<abs(sum-m)<<"\n";

}


    /*
    int t;
    cin >> t;
    vector<int>r;
    vector<int>l;
    map<int,int>mp;
    map<int,int>li;
    map<int,int>rt;
    for (int i=0; i<t; i++)
    {
        char c;
        int id;
        cin >> c >> id;
        mp[id]++;
        if (c=='R')
        {
            if (mp[id]==1)
            {
                r.push_back(id);
                rt[id]++;

            }
            else if (c=='L')
            {
                if (mp[id]==1)
                {
                    l.push_back(id);
                    li[id]++;
                }
                else if (c=='?')
                {


                }
            }*/

    return 0;
}
