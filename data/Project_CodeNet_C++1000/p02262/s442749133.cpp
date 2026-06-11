#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

long long cnt;
int a[1000005];
vector<int> G;

void insertsort(int a[], int n, int g){
    for(int i = g; i < n; i++){
        int j = i - g;
        int v = a[i];
        while(j >= 0 && a[j] > v){
            a[j + g] = a[j];
            j -= g;
            cnt ++;
        }
        a[j + g] = v;
    }
}

void shellsort(int a[], int n){
    for(int h = 1; h <= n;){
        G.push_back(h);
        h = h * 3 + 1;
    }

    for(int i = G.size() - 1; i >= 0; i --){
        insertsort(a, n, G[i]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    shellsort(a, n);
    printf("%d\n", G.size());
    for(int i = G.size() - 1; i >= 0; i--){
        printf("%d", G[i]);
        if(i) printf(" ");
    }
    puts("");
    cout << cnt << endl;
    for(int i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}

