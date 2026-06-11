#include <bits/stdc++.h>
using namespace std;
int main(void){
    int k;
    long long ans;
    cin>>k;
    
    queue<long long> lun;
    for(int i=1; i<=9; i++){
        lun.push(i);
    }
    
    for(int i=0; i<k-1; i++){
        ans=lun.front();
        if(ans%10!=0){
            lun.push(10*ans+(ans%10)-1);
        }
        lun.push(10*ans+(ans%10));
        if(ans%10!=9){
            lun.push(10*ans+(ans%10)+1);
        }
        lun.pop();
    }
    
    cout<<lun.front()<<endl;
    return 0;
}