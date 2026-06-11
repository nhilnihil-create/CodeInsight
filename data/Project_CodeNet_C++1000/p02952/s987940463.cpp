#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        string tmp=to_string(i);
        if(tmp.size()%2==1){
            ans++;
        }
    }
    cout<<ans<<endl;
}
