#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int x,n,p[100],min=1000;
    cin>>x>>n;
    int minn=x;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p,p+n);
    for(int i=0;i<=101;i++){
        for(int j=0;j<n;j++){
            if(p[j]==i)break;
            else if(j==n-1&&min>abs(x-i)){
                min=abs(x-i);
                minn=i;
            }
        }
    }
    cout<<minn<<"\n";
}