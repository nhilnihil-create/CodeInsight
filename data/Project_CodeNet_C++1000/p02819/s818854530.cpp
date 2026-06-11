#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef long int li;

int main()
{
    IOS;
    //freopen("fr.txt","r",stdin);
    int x;
    cin>>x;
    while(1){
       
        bool ok=true;
        for(int i=2;i*i<x;i++){
            if(x%i==0)
                ok=false;
        }
        if(ok){
            cout<<x<<endl;
            break;
        }
         x++;
    }
    return 0;
}