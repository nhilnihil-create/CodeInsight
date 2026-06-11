#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

//define counter class
class Counter{
    int cnt;
public:
    Counter():cnt(0){}
    int show(){return cnt;}
    void up(){cnt++;}
    void down(){cnt--;}
};
long long cnt;
vector<int> G;

//define insertion sort
void insertsort(int* A, int n, int g){
    for(int i=g;i<n;++i){
        int v=A[i];
        int j=i-g;
        while(j>=0 && A[j]>v){
            A[j+g]=A[j];
            j-=g;
            ++cnt;
        }
        A[j+g]=v;
    }
}

void shellsort(int* A,int n){
    for(int h=1;;){
        if(h>n) break;
        G.push_back(h);
        h=3*h+1;
    }
    for(int i=G.size()-1;i>=0;--i){
        insertsort(A,n,G[i]);
    }
    cout<<G.size()<<"\n";
    for(int i=G.size()-1;i>=0;--i){
        cout<<G[i];
        if(i) cout<<" ";
    }
    cout<<"\n";
    cout<<cnt<<"\n";
    for(int i=0;i<n;++i){
        cout<<A[i]<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    int* array=new int[n];
    for(int i=0;i<n;++i){cin>>array[i];}
    cnt=0;
    shellsort(array,n);
    delete[] array;
}