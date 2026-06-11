#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count=0;
    // This is brute force.
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<n;j++){
    //         for(int k=1;k<n;k++){
    //             if(i*j+k==n)
    //             count++;
    //         }
    //     }
    // }

    // for(int i=1;i<n;i++){
    //     count+=(n-1)/i;
    // }

    for(int i=1;i<n;i++){
        for(int j=1;j*i<n;j++)
        count++;
    }
    cout<<count<<"\n";
    return 0;
}