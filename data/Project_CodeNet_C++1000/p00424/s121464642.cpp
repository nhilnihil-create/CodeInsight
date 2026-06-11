#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n==0)return 0;
    
    char a[n];
    char b[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    
    int count;
    cin>>count;
    
    char ans[count];
    
    for(int p=0;p<count;p++)cin>>ans[p];
    if(a[1]==ans[3])cout<<"AAAAA"<<endl;
    
    for(int j=0;j<count;j++){
        for(int l=0;l<n;l++){
            if(ans[j]==a[l]){
                ans[j]=b[l];
                break;
            }
        }
    }
    
    for(int q=0;q<count;q++)cout<<ans[q];
    cout<<endl;
    }
}