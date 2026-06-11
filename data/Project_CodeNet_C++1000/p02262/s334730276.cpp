#include <iostream>
#include <cmath>

using namespace std;
int cnt=0;
void insertionSort(int A[],int n,int g){
    for(int i=g;i<n;i++){
        int v=A[i];
        int j=i-g;
        while(j>=0 && A[j]>v){
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}
void shellSort(int A[],int n){
    cnt = 0;
    int m = 0;
    int G[100];
    int aG=0;
    for(int i=0;i<100;i++){
        aG=3*aG+1;
        G[i]=aG;
        if(G[i]>n){
            m=i;
            break;
        }
    }
    cout << m << endl;
    for(int i = m-1;i>=0;i--){
        if(G[i]>n)continue;
        insertionSort(A, n, G[i]);//G[i]);
        cout << G[i];
        if (i!=0){
            cout << " ";
        }
    }
    cout << endl;
}


int main(){
    int n;
    cin >> n;
    int array[1000000];
    bool flag=true;
    int count=0;
    for(int i=0;i<n;i++){
        cin >> array[i];
    }
    shellSort(array,n);
    cout <<cnt<<endl;
    for(int i=0;i<n;i++){
        cout << array[i] << endl;
/*        if(i!=n-1){
            cout << " ";
        }*/
    }
//    cout << endl;
//    cout << count << endl;
    return 0;
}
