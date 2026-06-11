#include<bits/stdc++.h>

using namespace std;

int main(){
    string s,c;
    int n,i,j,k,l,sum=0;
    cin>>n>>l;
    int f[n];
    for(i=0;i<n;i++){
            f[i]=l+i;
            sum+=f[i];
    }
    int dif=INT_MAX,flag=0;
    for(i=0;i<n;i++){
        dif=min(abs(f[i]),dif);
        //cout<<"This is diff "<<dif<<endl;
        if(dif==abs(f[i])){flag=f[i];}
    }
    cout<<sum-flag;



    return 0;
}
