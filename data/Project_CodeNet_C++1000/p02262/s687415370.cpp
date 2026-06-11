#include <iostream>
#include <cstring>
using namespace std;
int n,a[1000000];
int g[100];
int cnt=0;

//void shellsort(int j){
//    int h=g[j];
//    int i;
//    for(i=h;i<n;i++){
//        int v=a[i];
//        int k=i-h;
//        while(k>=0&&a[k]>v){
//            a[k+h]=a[k];
//            cnt=cnt+1;
//            k-=h;
//        }
//        a[k+h]=v;
//    }
//}

void shellsort(int j){
    int h=g[j];
    int i;
    for(i=0;i<h;i++){
        int j=i+h;
        while(j<n){
            int k=j-h;
            int v=a[j];
            while(k>=0&&a[k]>v){
                a[k+h]=a[k];
                cnt++;
                k-=h;
            }
            a[k+h]=v;
            j=j+h;
        }
    }
}

int main()
{
    cin>>n;
    int i,j,k;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    memset(g,0,sizeof(g));
    i=0;
    g[i]=1;
    //??????????????????
    if(n==1)i=1;
    else
        while(g[i]<n){g[i+1]=g[i++]*3+1;}
    cout<<i<<endl;
    for(j=i-1;j>=0;j--){
        cout<<g[j];
        if(j!=0)cout<<" ";
    }
    cout<<endl;
    for(j=i-1;j>=0;j--){
        shellsort(j);
    }
    cout<<cnt<<endl;
    for(k=0;k<n;k++){
        cout<<a[k]<<endl;
    }
    return 0;
}