#include <iostream>
using namespace std;
int f(int x,int y){
        return (x-y)*(x-y);
    }
int main(void){
    int n;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    int ans=99999999;
    for(int k=0;k<100;k++){
        int hoge=0;
        for (int y=0;y<n;y++){
            hoge=hoge+f(x[y],k);
        }
        ans=min(ans,hoge);
    }
    cout<<ans<<endl;
}
