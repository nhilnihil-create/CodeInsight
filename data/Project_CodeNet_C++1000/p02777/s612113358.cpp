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
        string s,t;
        cin>>s>>t;
        int sb,tb;
        cin>>sb>>tb;
        string u;
        cin>>u;
        if(u==t)
        {
            tb--;
        } else if(u==s){
            sb--;
        }
        cout<<sb<<" "<<tb;
    }
    return 0;
}