#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e5+10;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n%2){
        for(int i=1;i<=m;i++){
            cout<<i<<" "<<n-i<<endl;
        }
    }
    else{

            int r=n;
            for(int i=1;i<=m;i++){
                if(i==n/4+1){
                    r--;
                }
                cout<<i<<" "<<r<<endl;
                r--;
            }


        }
}

