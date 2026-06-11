#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s,k;
    cin>>s>>k;
    int c=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]!=k[i])c++;
    }
    cout<<c<<endl;

}
