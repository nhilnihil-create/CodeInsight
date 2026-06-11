#include<bits/stdc++.h>
using namespace std;
int main(){
    int ma=0;
    for(int i=0;i<2;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            int a;
            cin>>a;
            sum+=a;
        }
        ma=max(ma,sum);
    }
    cout<<ma<<endl;
    return 0;
}