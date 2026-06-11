#include <iostream>
#include <cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define MAX 100
long long cnt = 0;
int l;
int n;
int a[1000000];
vector<int> G;

void insertionSort(int a[], int n, int g){
    for (int i = g; i < n; i++) {
        int v = a[i];
        int j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j  -= g;
            cnt++;
        }
        a[j + g] = v;
    }
    
}

void shellSort(int a[], int n){
    for (int h = 1; ; ) {
        if(h > n)break;
        G.push_back(h);
        h = 3*h + 1;
    }
    
    for (int i = G.size() - 1;i >= 0 ; i--) {
        insertionSort(a, n, G[i]);
    }
}

int main(){
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cnt = 0;
    
    shellSort(a, n);
    
    cout<<G.size()<<endl;
    for (int i = G.size() - 1; i >= 0; i--) {
        printf("%d",G[i]);
        if (i) {
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",cnt);
    for(int i = 0;i < n;i++)    printf("%d\n",a[i]);
    
    return 0;

}