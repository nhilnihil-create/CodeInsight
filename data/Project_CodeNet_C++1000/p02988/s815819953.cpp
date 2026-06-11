#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int p[n];
    int k[3];
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(i>=2){
            k[0]=p[i-2];
            k[1]=p[i-1];
            k[2]=p[i];
            sort(k,k+3);
            if(k[1]==p[i-1])ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}