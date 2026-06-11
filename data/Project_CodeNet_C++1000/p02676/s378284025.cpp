#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n;
    fflush(stdin);
    cin>>s;
    int l=s.length();
    if(n<l){
        for(int i=0;i<n;i++)
        {
            cout<<s[i];
        }
        cout<<"...";
    }
    else{
        for(int i=0;i<l;i++)
        {
            cout<<s[i];
        }
    }


}
