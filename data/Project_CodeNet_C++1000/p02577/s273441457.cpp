///In the name of Almighty Allah(swt).

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll sum=0,i,m;
    for(i=0; i<s.size(); i++){
        m = s[i]-48;
        sum += m;
    }

    if(sum % 9 ==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    return 0;
}

