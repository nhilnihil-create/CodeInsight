#include<stdio.h>
#include<vector>
using namespace std;
long long cat;
int l,a[1000000];
int n;
vector<int>M;
void insertionsort(int a[],int n,int g){
    for(int i=g;i<n;i++){
        int v=a[i];
        int j=i-g;
        while(j>=0&&a[j]>v){
            a[j+g]=a[j];
            j-=g;
            cat++;
        }
    a[j+g]=v;
    }
}
void xier(int a[],int n){
    for(int h=1; ;){
        if(h>n)break;
        M.push_back(h);
        h=3*h+1;
    }
    for(int i=M.size()-1;i>=0;i--){
        insertionsort(a,n,M[i]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    cat=0;
    xier(a,n);
    printf("%d\n",M.size());
    for(int i=M.size()-1;i>=0;i--){
        printf("%d",M[i]);
        if(i)printf(" ");
    }printf("\n");
    printf("%d\n",cat);
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }

return 0;
}