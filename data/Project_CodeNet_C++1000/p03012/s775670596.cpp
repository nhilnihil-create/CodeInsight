#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        int w;
        cin>>w;
        arr[i]=w;
        sum+=w;
    }
    int min=sum;
    int summy=0;
    for(int j=0;j<n;j++){
        summy+=arr[j];
        if(abs(sum-summy-summy)<min){
             min=abs(sum-summy-summy);
         }
    }
    cout<<min<<endl;
}