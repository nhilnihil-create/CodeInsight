#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int A,B;
    cin>>A>>B;

    int st=A/0.08;
    int ed=(A+1)/0.08;

    int ans=-1;
    for(int i=st;i<=ed;i++){
        if((int)(i*0.08)==A&&i/10==B){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}