#include<bits/stdc++.h>
using namespace std;

vector<int> arr[1000001];
int main(){
    int n;
    cin>>n;
    // arr[1].push_back(1);
    for(int i=2; i<1000001; i++){
        if(arr[i].size()==0){
            int k=i;
            while(k<1000001){
                arr[k].push_back(i);
                k+=i;
            }
        }
    }
    int coun[1000001];
    for(int i=0; i<1000001; i++){
        coun[i]=0;
    }
    int max=0;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        for(int k:arr[a]){
            coun[k]++;
            if(coun[k]>max)
                max=coun[k];
        }
    }
    // cout<<max<<endl;
    if(max==n){
        cout<<"not coprime"<<endl;
    }
    else if(max==1||max==0){
        cout<<"pairwise coprime"<<endl;
    }
    else{
        cout<<"setwise coprime"<<endl;
    }
    return 0;
}