#include <iostream>

using namespace std;
int arr[250];
int main(){
    int x,y;
    cin>>x>>y;
    arr[1] = 300000;
    arr[2] = 200000;
    arr[3] = 100000;
    if(x==1 && y==1){
        cout<<1000000<<endl;
        return 0;
    }
    cout<<arr[x]+arr[y]<<endl;
}
