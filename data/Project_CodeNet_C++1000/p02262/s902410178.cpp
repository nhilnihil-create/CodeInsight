#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

void shell_sort(int R[],int n);
void insertion_sort(int R[],int n,int g);

int cnt;
int l;
int R[1000000];
int n;
std::vector<int> G;

void shell_sort(int R[],int n){
    for(int h = 1;;){
        if(h > n) break;
        G.push_back(h);
        h = 3 * h + 1;
    }

    for(int i = G.size() - 1;i >= 0;i--) insertion_sort(R,n,G[i]);
}

void insertion_sort(int R[],int n,int g){
    for(int i = g;i < n;i++){
        int v = R[i];
        int j = i - g;
        while((j >= 0) && (R[j] > v)){
            R[j + g] = R[j];
            j = j - g;
            cnt++;
        }
        R[j + g] = v;
    }
}

int main(int argc, char const *argv[])
{
    std::cin >> n;

    for(int i = 0;i < n;i++) scanf("%d",&R[i]);
    cnt = 0;

    shell_sort(R,n);

    std::cout << G.size() << std::endl;
    for(int i = G.size() - 1;i >= 0;i--){
        printf("%d",G[i]);
        if(i) printf(" ");
    }
    printf("\n");
    printf("%d\n",cnt);
    for(int i = 0;i < n;i++) printf("%d\n",R[i]);

    return 0;
}

