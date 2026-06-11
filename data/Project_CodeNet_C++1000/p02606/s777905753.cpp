#include<bits/stdc++.h>
using namespace std;


int main(){

int p,q,r;
cin>>p>>q>>r;

int check = 0 ;

for(int i = 1; ; i++){
    int ans = r*i;
    if(ans>q) break;

    if(p<=ans && ans<=q) check++;
}
cout<<check<<endl;



}
