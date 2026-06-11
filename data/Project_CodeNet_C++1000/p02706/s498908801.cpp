#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n,m;
    cin>>n>>m;
    int a;
    for(int i=0; i<m; i++){
        cin>>a;
        n -= a;
    }
    if(n < 0){
        cout<<"-1"<<endl;
    }else{
        cout<<n<<endl;
    }
}
