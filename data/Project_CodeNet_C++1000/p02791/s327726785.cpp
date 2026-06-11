#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int N;
    cin>>N;

    int p;
    int minnum=2e5+1;
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>p;

        if(p<=minnum){
            ans++;
        }

        if(minnum>p){
            minnum=p;
        }
    }

    cout<<ans<<endl;

    return 0;
}