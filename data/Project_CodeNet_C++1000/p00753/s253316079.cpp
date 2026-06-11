#include<iostream>
using namespace std;

int p[300000];

int main(){
    int n;
    p[0]=p[1]=-1;
    for(int i=2;i<300000;i++){
        if(!p[i]){
            p[i]=1;
            for(int j=i+i;j<300000;j+=i)p[j]=-1;
        }
    }
    while(1){

        int ans=0;
        cin >> n;

        if(n==0)break;

        for(int i=n+1;i<=n+n;i++){
            if(p[i]==1)ans++;
        }
        cout << ans <<endl;
    }
}
