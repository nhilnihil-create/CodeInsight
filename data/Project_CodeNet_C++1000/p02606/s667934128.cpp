#include <bits/stdc++.h>
using namespace std;
int main(){
    int l;
    int r;
    int d;
    cin>>l>>r>>d;
    int x=0;
    for(int i=l;i<=r;i++){
        if(i%d==0){
            x++;
        }
    }
    cout<<x<<endl;

}


