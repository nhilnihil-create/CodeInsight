#include<bits/stdc++.h>
using namespace std;

int sosuuCheck(int x);

int main(){
    int n;
    while(1){
        cin>>n;     if(n==0)break;

        int ans=0;
        for(int i=n+1;i<=n*2;i++){
            ans += sosuuCheck(i);
        }


        cout<<ans<<endl;
    }


    return 0;
}

int sosuuCheck(int x){


    if(x==1)return 1;
    else if(x==2)return 1;
    else if(x%2==0)return 0;
    else{
        int i=3;
        while(i<=sqrt(x)){
            if(x%i==0) return 0;

            i+=2;
        }
    }

    return 1;
}

