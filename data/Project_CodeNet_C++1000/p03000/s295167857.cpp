#include <iostream>
using namespace std;
int main(void){
    int n,x,l,d=0,ans=1;
    
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>l;
        d += l;
        
        if(d<=x){ ans +=1; }
    }
    
    cout<<ans<<"\n";
    return 0;
}
