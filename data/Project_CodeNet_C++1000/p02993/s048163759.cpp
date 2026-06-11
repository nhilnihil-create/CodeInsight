#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    string s;
    cin>>s;
    int l=s.size();
    bool ans=false;
    for(int i=0;i<l-1;i++){
        if(s[i]==s[i+1]){
            ans=false;
            break;
        }
        else{
            ans=true;
        }
    }
    if(ans)  cout<<"Good";
    else     cout<<"Bad";
}
