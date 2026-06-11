#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,a,a1=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a;
        a1+=a;
    }
    if(n<a1){
        cout<<-1<<endl;
    }else{
        cout<<n-a1<<endl;
    }
    
}
