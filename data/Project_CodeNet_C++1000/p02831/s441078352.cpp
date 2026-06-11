#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,i=1;
    long long c;
    cin>>a>>b;

    while(true){
        c=a*i;
        if(c%b==0){
            cout<<c<<endl;
            return 0;
        }
        i++;
    }
}
