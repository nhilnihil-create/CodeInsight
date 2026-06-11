#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int n;cin>>n;

    string str;
    cin>>str;

    int ans=0;
    for(int i=0;i<n;i++){
        if(str[i]=='A'){
            i++;
            if(str[i] && str[i]=='B'){
                i++;
                if(str[i] && str[i]=='C'){
                    ans++;
                }
                else
                    i=i-2;
            }
            else
            {
                i--;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}