#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x[110];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    int vmin=100000000;
    for(int p=1;p<=100;p++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=pow(x[i]-p,2);
        }
        vmin=min(vmin,sum);
    }
    cout<<vmin<<"\n";
    return(0);
}