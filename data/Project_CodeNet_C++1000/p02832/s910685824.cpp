#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin>>n;
    
    int k=1,x=0,count=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==k){
            
            k++;
        }
    }
    if(k==1)    cout <<-1 << endl;
    else        cout<<n-k+1<<endl;
    return 0;
}
