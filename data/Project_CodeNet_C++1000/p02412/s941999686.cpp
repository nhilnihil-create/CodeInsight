#include <iostream>
#include <cmath>
//#include <string>
using namespace std;
int main(){

    while(true){
    int n,x;
    cin>>n>>x;
    int ans=0;
        if(n==0&&x==0)break;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int u=j+1;u<=n;u++){
                if(i+j+u==x)ans++;
            }
        }
    }
    cout<<ans<<endl;
    
    }
    
    return 0;
}
