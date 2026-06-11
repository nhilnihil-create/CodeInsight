//
//  main.cpp
//  ABC136B
#include <iostream>
using namespace std;
bool f(int i){
    int dgt=0;
    while (i) {
        dgt++;
        i/=10;
    }
    return dgt%2==1; // 奇数ならtrue 偶数ならfalseを返す
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(f(i)==true) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
