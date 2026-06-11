#include<bits/stdc++.h>
using namespace std;
int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a>b){
        for(int i=0; i<a; i++){
            cout<<b;
        }
    }
    else if(b>a){
        for(int i=0; i<b; i++){
            cout<<a;
        }
    }
    else{
        for(int i=0; i<a; i++){
            cout<<a;
        }
    }
    return 0;
}
