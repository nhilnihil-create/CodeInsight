#include <bits/stdc++.h>
using namespace std;

int main()
{
     long long n,k;
    cin>>n>>k;
    vector<long long>v(n);

    long long cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.begin()+n);
    if(k>=n){
        cout<<0<<endl;
    }
    else{
        for(int i=0;i<n-k;i++){
            cnt+=v[i];
        }
        cout<<cnt<<endl;
    }

    return 0;
}
