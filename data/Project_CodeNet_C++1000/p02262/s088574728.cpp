#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> G;

long cont;

void insertSort(int a[],int n,int g){
    int i,j,v;
    for (i = g; i < n; ++i) {
        v=a[i];
        j=i-g;
        while (j>=0&&a[j]>v){
            a[j+g]=a[j];
            j-=g;
            cont++;
        }
        a[j+g]=v;
    }
}

void shellSort(int a[],int n){
    //????????°???G={1,4,13,40??????}
    int h=1;
    int i;
    while (1){
        if (h>n)
            break;
        G.push_back(h);
        h=3*h+1;
    }

    for (i = G.size()-1; i >=0; --i) {
        insertSort(a,n,G[i]);
    }
}

int main() {
    int n,i,a[1000001];
    cont=0;
    cin>>n;
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }
    shellSort(a,n);

    cout<<G.size()<<endl;

    for (i = G.size()-1; i >=0 ; --i) {
        cout<<G[i];
        if (i)
            cout<<" ";
    }

    cout<<endl;
    cout<<cont<<endl;

    for (i = 0; i < n; ++i) {
        cout<<a[i]<<endl;
    }
    return 0;
}