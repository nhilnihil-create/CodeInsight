#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long cnt=0;
vector<int> G;

void insertionSort(int a[],int n,int g){
    for(int i=g;i<n;i++){
        int v=a[i];
        int j=i-g;
        while(j>=0 && a[j]>v){
            a[j+g]=a[j];
            j-=g;
            cnt++;
        }
        a[j+g]=v;
    }
}

void shellSort(int a[],int n){
    for(int h=1; ;){
        if(h>n) break;
        G.push_back(h);
        h=h*3+1;
    }
    for(int i=G.size()-1;i>=0;i--){
        insertionSort(a,n,G[i]);
    }
}

int main(void){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cnt=0;
    shellSort(a,n);
    string c="";
    
    cout<<G.size()<<endl;
    for(int i=G.size()-1;i>=0;i--){
        cout<<c<<G[i];
        c=" ";
    }
    cout<<endl;
    cout<<cnt<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<endl;
}

