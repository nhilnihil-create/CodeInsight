#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int g[15];
int a[1000000+100];
long long res=0;
int m;
void getG(){
    g[0]=1;
    m++;
    for(int i=1;;i++){
        g[i]=g[i-1]*3+1;
       if(g[i]>n)
        break;
       m++;
    }
}

void Insertion_sort(int g){

    for(int i=g;i<n;i++){
        int val=a[i];
        int j=i-g;
        while(j>=0 && a[j]>val){
            a[j+g]=a[j];
            res++;
            j-=g;
        }
        a[j+g]=val;
    }
}

void shell_sort(){
    getG();
    for(int i=14;i>=0;i--){
        Insertion_sort(g[i]);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    shell_sort();
    cout<<m<<endl;
    cout<<g[m-1];
    for(int i=m-2;i>=0;i--)
        cout<<" "<<g[i];
    cout<<endl;
    cout<<res<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
}