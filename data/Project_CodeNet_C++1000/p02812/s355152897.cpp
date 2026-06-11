#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    long long t , n,count= 0;
    string s;
    cin>>n>>s;
    //n =  s.size();
    for(int i = 0;i<n-2;i++)
    {
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')
        {
            count++;
            i= i + 2;
        }
    }
    cout<<count;
    return 0;
}