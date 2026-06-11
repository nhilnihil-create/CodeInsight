#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static int cnt;
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i != n-1)
            cout << endl;
    }
}
void insertSort(int a[],int n,int g){
    for(int i=g;i<n;i++){
        int v = a[i];
        int j = i-g;
        while(j>=0 && a[j]>v){
            a[j+g] = a[j];
            j = j - g;
            cnt ++;
        }
        a[j+g] = v;
    }
}
int shellSort(int a[],int n){
    cnt = 0;
    vector<int> G;
    int beginNum = 1;
    G.push_back(beginNum);
    while(3*beginNum+1 <= n){
        int temp = 3*beginNum+1;
        G.push_back(temp);
        beginNum = temp;
    }
    int m = G.size();
    cout << m << endl;
    for(int i=m-1;i>=0;i--){
        cout << G[i];
        if(i!=0)
            cout << " ";
    }
    cout << endl;
    for(int k=m-1;k>=0;k--)
        insertSort(a,n,G[k]);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    if(n>=1 && n<=1000000){
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        shellSort(a,n);
        cout << cnt << endl;
        printArray(a,n);
    }else{
        return 0;
    }
    return 0;
}