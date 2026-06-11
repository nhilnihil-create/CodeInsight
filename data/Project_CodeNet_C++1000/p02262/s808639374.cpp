#include <iostream>
using namespace std;

int insertionSort(int a[],int n,int g,int cnt){
    int i,j,v;
    for(i=g;i<n;i++){
        v=a[i];
        j=i-g;
        while(j>=0&&a[j]>v){
            a[j+g]=a[j];
            j-=g;
            cnt++;
        }
        a[j+g]=v;
    }
    return cnt;
}

int shellSort(int a[],int g[],int m,int n){
    int cnt=0;
    int i;
    for(i=0;i<m;i++){
        cnt=insertionSort(a,n,g[i],cnt);
    }
    return cnt;
}

int main(void){
    int n,a[1000000];
    cin>>n;
    int i;
    for(i=0;i<n;i++)cin>>a[i];
    
    if(n==1){
        cout<<1<<endl<<1<<endl<<0<<endl<<a[0];
        return 0;
    }
    
    int m=0,tmp=n,g[20];
    while(tmp>1){
        tmp/=2;
        g[m]=tmp;
        m++;
    }
    int cnt=shellSort(a,g,m,n);
    
    cout<<m<<endl;
    for(i=0;i<m-1;i++)cout<<g[i]<<" ";
    cout<<g[m-1]<<endl;
    cout<<cnt<<endl;
    for(i=0;i<n;i++)cout<<a[i]<<endl;
    return 0;
}
