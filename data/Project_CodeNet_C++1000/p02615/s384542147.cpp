#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> s(n+1);
    for(int i =1 ;i<n+1;i++)
    {
        cin>>s[i];
    }
    sort(s.begin()+1,s.end(),greater<>());
    // vector<int> happy(n,0);
    long long  ans = 0;
    int flag = 0;
    int x  =0,i = n/2,j=n/2;
    ans = s[1];
    
    for(int i = 3 ;i<=n;i++)
    ans += s[(i+1)/2];

    cout<<ans<<endl;
    return 0;

}