#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin>>N;
    int a[N],b[N];
    for (int i=0;i<N;i++){
        cin>>a[i];
        b[a[i]-1]=i+1;
    }
    for(int i=0;i<N-1;i++){
        cout<<b[i]<<" ";
    }
    cout<<b[N-1]<<endl;

}
