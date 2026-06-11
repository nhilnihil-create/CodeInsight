#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[104],b[105];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int cnt=0,f=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            cnt++;
            if(cnt==3) {
                    f=1;
                    break;
            }

        }
        else cnt=0;
    }
    if(f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main()
{
    solve();
}
