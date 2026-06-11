#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
bool flag = 0;

for(int i=1 ; i<=9 ; i++){
    int div;
    if(n%i==0){
        div = n/i;
        if(div>=1 && div<=9)
            flag = 1;
    }
}

if(flag) cout<<"Yes"<<endl;
else cout<<"No"<<endl;

}
