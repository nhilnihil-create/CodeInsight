#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,x;
    cin>>n>>x;
    
    int d=0,ans=1;
    for(int i=0;i<n;i++){
        int newp;
        cin>>newp;
        int newd=d+newp;
        if(newd<=x)
            ans++;
        else
            break;
        
        d= newd;
    }
cout<<ans;
}
