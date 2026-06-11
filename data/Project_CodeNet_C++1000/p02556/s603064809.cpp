#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int N=2e5+10;

int n;
int z[N],t[N];


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        z[i]=a+b;
        t[i]=a-b;
    }
    int max_z=-1e9,min_z=1e9;
    int max_t=-1e9,min_t=1e9;
    for(int i=0;i<n;++i){
        if(z[i]>max_z) max_z=z[i];
        if(z[i]<min_z) min_z=z[i];

        if(t[i]>max_t) max_t=t[i];
        if(t[i]<min_t) min_t=t[i]; 
    }
    cout<<max(max_z-min_z,max_t-min_t)<<endl;
    return 0;
}