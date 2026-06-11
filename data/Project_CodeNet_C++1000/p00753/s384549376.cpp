#include <iostream>
#include <string>
using namespace std;

int main(){

    int n;

    while(cin>>n,n){
        if(n==1) cout<<1<<endl;
        else{
        int count=0;
        for(int i=n+1;i<=2*n;i++){
            int check=0;
            for(int j=2;j*j<=i;j++){
                if(i%j==0) check=1;
            }
            if(check==0) count++;
        }

        cout<<count<<endl;
        }
    }

    return 0;

}
