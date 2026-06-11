#include<iostream>[
using namespace std;
int main(){
    int n;
    while(cin>>n,n){
        int a[5000];
        for(int i=0;i<n;i++)cin>>a[i];
        int mxm=-1000001;
        for(int i=0;i<n;i++){
            int b=0;
            for(int j=i;j<n;j++){
                b+=a[j];
                mxm=max(mxm,b);
            }
        }
        cout<<mxm<<endl;
    }
    return 0;
}