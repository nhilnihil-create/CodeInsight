#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N,R;
    cin>>N>>R;
    if(N<=10){ 
    int ans=R+100*(10-N);
    cout<<ans<<endl;
    }else
    cout<<R<<endl;
return 0;
}
