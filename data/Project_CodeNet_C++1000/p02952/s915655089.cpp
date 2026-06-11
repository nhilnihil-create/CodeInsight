#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    int n;cin>>n;
    int keta=log10(n);
    int count =0;
    for(int i=1;i<=keta+1;i++){
        if(i%2==1){
            if(i==keta+1) count+=n-pow(10,keta)+1;
            else count += pow(10,i)-pow(10,i-1);

        }

    }
    cout << count;
    
}