#include <iostream>
#include <vector>

using namespace std;

int cnt;

int insertionSort(int *A,int n,int g){
    int flg=0;
    for (int i=g;i<n;i++){
        int v=A[i];
        int j=i-g;
        while (j>=0 && A[j]>v){
            flg=1;
            A[j+g]=A[j];
            j=j-g;
            cnt++;
        }
        A[j+g]=v;
    }
    if (!flg && g==1){
        //???????????\????????????g???1
        return 1;
    }
    else
        return 0;
}

void shellSort(int *A,int n){
    cnt=0;
    vector<int> G;
    int g=n-1;
    int flg;
    do{
        G.push_back(g);
        flg=insertionSort(A,n,g);
        g=(g*10)/13;
        if (g==0){
            g=1;
        }
    }while (!flg);
    //m
    cout<<G.size()<<endl;
    for (int i=0,l=G.size();i<l;i++){
        cout<<G[i];
        if (i!=l-1){
            cout<<" ";
        }
    }
    cout<<endl;
    cout<<cnt<<endl;
    for (int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
}

int main(){
    int *a;
    int n;
    cin>>n;
    a=new int [n];
    if (a==NULL){
        cout<<"Error!"<<endl;
        return -1;
    }
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    shellSort(a,n);
    delete [] a;
    return 0;
}