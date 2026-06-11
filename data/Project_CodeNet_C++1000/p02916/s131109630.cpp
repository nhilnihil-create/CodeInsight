#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>c[i];
    }
    int x=0,num, prenum;
    for(int i=0; i<n; i++){
        num=a[i]-1;
        x+=b[num];
        if(i!=0){
            prenum=a[i-1]-1;
            if(num-prenum==1){
                x+=c[prenum];
            }
        }
    }
    cout<<x;
    return 0;
}
