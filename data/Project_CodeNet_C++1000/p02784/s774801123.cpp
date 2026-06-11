#include<bits/stdc++.h>

using namespace std;

int main()

{
    int a,b;
    cin>>a>>b;
    
    while(b--){
        int x;
        cin>>x;
        if((a-=x)<=0){
        cout<<"Yes";
          return 0;
        }
    }
    cout<<"No";

}